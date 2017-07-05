#!/usr/bin/perl -w

package Indigo::Renderer;

use strict;

use File::Basename;
use Carp;

our $VERSION = do { my @r = (q$Revision: 1.4 $ =~ /\d+/g); sprintf "%d."."%03d" x $#r, @r };


sub new {
	my ($class) = @_;

	# [source] directory
	# warnings mode: off/[warning]/<!-- warning -->/eval coderef?
	# full backtrace
	my $self = {
		backtrace		=>	1,
		template_dir	=>	undef,
	};

	# return renderer object
	return bless $self, $class;
}


sub warning {
	my ($self, $coderef) = @_;

	return $self->{warning} = ($coderef || $self->{warning});
}


sub template_dir {
	my ($self, $template_dir) = @_;

	return $self->{template_dir} = ($template_dir || $self->{template_dir});
}


sub cache_templates {
	my ($self, $dir) = @_;

	$dir ||= $self->{template_dir};

	local *TD;
	opendir(TD, $dir) || die("Can't open template dir '$dir': $!");
	while( my $entry = readdir(TD) ) {
		next if $entry eq '.' || $entry eq '..';

		my $path = "$dir/$entry";
		if (-d $path) {
			$self->cache_templates($path);
		} elsif (substr($entry, -3) eq '.it') {
			# cache template
			my %hash;
			warn("Caching $path\n");
			$self->render($path, \%hash);
		}
	}
	closedir(TD);
}


sub render {
	my ($self, $pathname, $data) = @_;

	if ($self->{template_dir} && substr($pathname, 0, 1) ne '/') {
		# $pathname is relative to $parent_pathname
		$pathname = $self->{template_dir} . '/' . $pathname;
	}
	
	my $template = $self->template($pathname, $self->{template_dir});

	# create render object with %data
	my $render = {
		renderer	=>	$self,
		stack		=>	[ ],
		data		=>	$data,
	};
	bless $render, 'Indigo::Renderer::Render';

	no strict 'refs';
	local %{"Indigo::Renderer::Template::"} = %{ $template->{namespace}  };
	# clean namespace from last time
	# this means undef'ing all HASH/ARRAY/SCALAR symbols (but leaving the symbols in existence)
	while( my ($key, $value) = each %{"Indigo::Renderer::Template::"} ) {
		if (my $ref = *{$value}{SCALAR}) {
			undef $$ref;
		}

		if (my $ref = *{$value}{HASH}) {
			undef %$ref;
		}

		if (my $ref = *{$value}{ARRAY}) {
			undef @$ref;
		}
	}

	${"Indigo::Renderer::Template::_render"} = $render;

	# present %data to package
	if ($data) {
		while( my ($key, $value) = each %$data) {
			my $ref = ref $value;
			if ($ref eq 'HASH') {
				%{"Indigo::Renderer::Template::$key"} = %$value;
			} elsif ($ref eq 'ARRAY') {
				@{"Indigo::Renderer::Template::$key"} = @$value;
			} elsif ($ref eq 'SCALAR') {
				${"Indigo::Renderer::Template::$key"} = $value;
			} elsif ($ref ne 'CODE' && $ref ne 'PACKAGE') {
				${"Indigo::Renderer::Template::$key"} = $value;
			}
		}
	}

	# process template
	my $output = '';
	open my $capture, ">", \$output;
	my $io = select($capture);

	$render->go($template->{compiled});

	select($io);
	close($capture);

	die $@ if $@;

	return $output;
}


sub template {
	my ($self, $pathname, $parent_pathname) = @_;

	my $rebuild = 0;

	if ($self->{templates}{$pathname}) {
		# check timestamps of all included files
		while(my ($component, $timestamp) = each %{$self->{templates}{$pathname}{components}}) { 
			if ($timestamp < (stat($component))[9]) {
				$rebuild = 1;
				last;
			}
		}
	} else {
		$rebuild = 1;
	}

	return $self->{templates}{$pathname} unless $rebuild;

	my %components;
	my $template = $self->build_template($pathname, \%components);

	$self->{templates}{$pathname}{components} = \%components;

	# compile in own namespace
	no strict 'refs';
	local %{"Indigo::Renderer::Template::"};
	$self->{templates}{$pathname}{namespace} = \%{"Indigo::Renderer::Template::"};

	$self->{templates}{$pathname}{compiled} = $self->compile_template($template);

	return $self->{templates}{$pathname};
}


sub compile_template {
	# clean of lexicals
	eval "package Indigo::Renderer::Template; no warnings; no strict; sub() { $_[1] }";
}


sub build_template {
	my ($self, $pathname, $components, $parent_pathname, $parent_line) = @_;

	my $template;

	if (ref $pathname) {
		$template = $$pathname;
	} else {
		if ($parent_pathname && substr($pathname, 0, 1) ne '/') {
			# $pathname is relative to $parent_pathname
			$pathname = dirname($parent_pathname) . '/' . $pathname;
		}
	
		local *T;
		unless (open(T, $pathname)) {
			my $caller = $parent_pathname ? " called from '$parent_pathname'" : '';
			my $err = $!;
			croak("Can't open template '$pathname': $err$caller");
		}
		$components->{$pathname} = (stat(T))[9];
		local $/ = undef;
		$template = <T>;
		close(T);
	}

	# ' and \ outside of <% and %> needs to be Perl-escaped
	$template =~ s/(^|%>)(.*?)(<%|$)/my @p = ($1, $2, $3); $p[1] =~ s|([\'\\])|\\$1|g; join('', @p)/sge;

	# <%=
	$template =~ s|<%=|<%print |g;

	# assign then print to allow <%h='selected' if $a == $b%> syntax

	# <%h=
	$template =~ s|<%h=(.*?)(?=%>)|';\$__p = undef; \$__p = $1; print \$_render->HTML_escape(\$__p) if defined \$__p|g;

	# <%hbr=
	$template =~ s|<%hbr=(.*?)(?=%>)|';\$__p = undef; \$__p = $1; print \$_render->HTML_BR_escape(\$__p) if defined \$__p|g;

	# <%u=
	$template =~ s|<%u=(.*?)(?=%>)|';\$__p = undef; \$__p = $1; print \$_render->URL_escape(\$__p) if defined \$__p|g;

	# <%j=
	$template =~ s|<%j=(.*?)(?=%>)|';\$__p = undef; \$__p = $1; print \$_render->JavaScript_escape(\$__p) if defined \$__p|g;


	# try pre-include compile
	my $pre_include = $template;

	# dummy <%include
	$pre_include =~ s|<%include (.*?)(?=%>)|<%|g;

	# <%
	$pre_include =~ s|<%|';|g;
	# %>
	$pre_include =~ s|%>|;print '|g;

	# compile test
	$self->compile_template("print '$pre_include'");

	if ($@) {
		my $err = $@;
		$err =~ s|.eval \d+. line (\d+)|$pathname line $1|g;
		croak("Pre-include compilation failed for template '$pathname':\n$err");
	}

	# <%include
	my @includes;
	# we have to do this the long way due to complexity involved
	# $template =~ s|<%include (.*?)(?=%>)|"';".$self->build_template($1, $components, $pathname)|eg;
	while( (my $pos = index($template, '<%include ')) != -1 ) {
		my $include_start = $pos + length('<%include ');
		my $include_end = index($template, '%>', $pos);
		croak("No end %> for <%include in template '$pathname'") if $include_end == -1; # XXX show line number

		my $start_line = (substr($template, 0, $pos) =~ tr|\n||) + 1;
		my $include = substr($template, $include_start, $include_end - $include_start);
		my $included_template = $self->build_template($include, $components, $pathname, $start_line);

		my $lines = ($included_template =~ tr|\n||) + 1;
		substr($template, $pos, length('<%include ' . $include)) = "<% $included_template";

		push(@includes, "[ $start_line, $lines ]");
	}

	# <%
	$template =~ s|<%|';|g;
	# %>
	$template =~ s|%>|;print '|g;

	my $include_data = join(', ', @includes);
	my $start_line = $parent_line || 1;
	$template = "\$_render->set_checkpoint('$pathname', $start_line, [ $include_data ]); eval { print '$template' }; \$_render->error_check; \$_render->clear_checkpoint;";

	# compile test
	$self->compile_template($template);

	if ($@) {
		my $err = $@;
		$err =~ s|.eval \d+. line (\d+)|$pathname line $1|g;
		croak("Compilation failed for template '$pathname':\n$err");
	}

	return $template;
}


# --- #


package Indigo::Renderer::Render;

use strict;
use Carp;


sub go {
	eval qq#
		package Indigo::Renderer::Template;

		my \$__previous_warn = \$SIG{__WARN__};
		local \$SIG{__WARN__} = sub { \$_render->warning(\$_[0], \$__previous_warn) };

		my \$__previous_die = \$SIG{__DIE__};
		local \$SIG{__DIE__} = sub { \$_render->error(\$_[0], \$__previous_die) };

		&{\$_[1]};
	#;
}


sub error_check {
	my ($render) = @_;

	if ($@) {
		my $err = $@;
		if ($err =~ m|.eval \d+.|) {
			$err =~ s|at .eval \d+. line (\d+)|'error at ' . $render->{stack}[0]{pathname} . ' line ' . real_line($render, 0, $1)|e;

			if ($render->{renderer}->{backtrace}) {
				my $bt = backtrace($render);
				$err =~ s|\.\n|$bt.\n|;
			}
		}

		die $err;
	}
}



# $SIG{WARN} = sub { $render->warning($_[0], $previous) }
# $previous is sub { $apache->warn }
# {warning} is undef

sub warning {
	my ($render, $message, $previous) = @_;

	$message =~ s|at .eval \d+. line (\d+)|'warning at ' . $render->{stack}[0]{pathname} . ' line ' . real_line($render, 0, $1)|e;

	if ($render->{renderer}->{backtrace}) {
		my $bt = backtrace($render);
		$message =~ s|\.\n|$bt.\n|;
	}

	if ($render->{renderer}->{warning}) {
		&{$render->{renderer}->{warning}}($message, $previous);
	} elsif ($previous && $previous != $SIG{__WARN__}) {
		&$previous($message);
	} else {
		warn($message);
	}
}


sub global_line_to_local {
	my ($render, $frame, $line) = @_;

	# print STDERR "global line to local line: $line -> ";
	$line += 1 - $render->{stack}[$frame]{start_line};
	# print STDERR "$line\n";

	$frame++;
	if ($frame < @{$render->{stack}}) {
		return global_line_to_local($render, $frame, $line);
	} else {
		return $line;
	}
}


sub local_line_to_relative {
	my ($render, $frame, $line) = @_;

	my $includes = $render->{stack}[$frame]{includes};
	foreach my $include (reverse @$includes) {
		if ($line > $include->[0]) {
			# print STDERR "local line to relative: line: $line -> ";
			$line += 1 - $include->[1];
			# print STDERR "$line\n";
		}
	}

	return $line;
}


sub real_line {
	my ($render, $frame, $line) = @_;

	return local_line_to_relative($render, $frame, global_line_to_local($render, $frame, $line));
}


sub backtrace {
	my ($render, $line) = @_;

	my $bt = '';
	for (my $i = 1; $i < @{$render->{stack}}; $i++) {
		$bt .= ", included at $render->{stack}[$i]{pathname} [backtrace] line " . local_line_to_relative($render, $i, $render->{stack}[$i - 1]{start_line});
	}

	return $bt;
}


sub error {
	my ($render, $message, $previous) = @_;

	$message =~ s|\.\n.| called|;

	if ($previous && $previous != $SIG{__DIE__}) {
		&$previous($message);
	} else {
		die "$message\n";
	}
}



sub set_checkpoint {
	my ($render, $pathname, $start_line, $includes) = @_;
	
	my $offset = 0;

	unshift(@{ $render->{stack} }, { pathname=>$pathname, start_line=>$start_line, includes=>$includes });
}


sub clear_checkpoint {
	my ($render, $abs_line) = @_;

	shift(@{ $render->{stack} });
}


sub HTML_escape {
	my ($render, $str) = @_;

	$str =~ s{&}{&amp;}gso;
	$str =~ s{<}{&lt;}gso;
	$str =~ s{>}{&gt;}gso;
	$str =~ s{\"}{&quot;}gso;

	return $str;
}


sub HTML_BR_escape {
	my ($render, $str) = @_;

	$str = $render->HTML_escape($str);
	$str =~ s[(\n\r|\r\n|\n|\r)][<br>$1]gso;

	return $str;
}


sub URL_escape {
	my ($render, $str) = @_;

	$str =~ s|([^A-Za-z0-9])|'%'.sprintf('%02x', ord($1))|seg;

	return $str;
}


sub JavaScript_escape {
	my ($render, $str) = @_;

	$str =~ s|\\|\\u005C|gso;
	$str =~ s|'|\\u0027|gso;
	$str =~ s|<|\\u003C|gso;
	$str =~ s|\n|\\u000A|gso;
	$str =~ s|\r|\\u000D|gso;

	return $str;
}


=pod

=head1 NAME

Indigo::Renderer - Render Perl-embedded template files

=head1 RCS

$Id: Renderer.pm,v 1.4 2007/05/23 19:10:06 dom Exp dom $

=head1 SYNOPSIS

  use Indigo::Renderer;

  %data = ( pid=>$$, inc=>sub { $_[0]++ } );

  $renderer = new Indigo::Renderer();
  $renderer->warnings( sub { print STDERR $_[0] } );
  $renderer->template_dir('templates');

  $html = $renderer->render('template.it', \%data);

  ---template.it---
  <HTML>
  I am <%=$_pathname%>
  PID: <% print $pid %>
  PID: <%= $pid %>
  PID: <%= $$ %>
  PID: <%include pid.it %>
  PID+1: <%= inc($pid) %>
  HTML-safe: <%h= $pid %>
  HTML-safe text block: <%hbr= $pid %>
  JS-safe: '<%j= $pid %>'
  URL-safe: <a href="?pid=<%u= $pid %>">
  </HTML>

=head1 DESCRIPTION

Template files contain raw output mixed with Perl escape tags. 
An example of use is to mix HTML with data produced by a CGI script.
Data is made available to the templates via an optional hash/hashref.
See NAMESPACE below for more details.

=head1 TAGS

The forms of tag are styled after ASP:

=item <% ... %>				- eval some perl

To escape from raw output into perl, use "<%" and "%>". 
Use C<print> to actually produce output to be inserted back into template.
e.g. <% $index++ %>

=item <%= ... %>			- simple value printing

If you just need to insert a value back, use "<%=" and "%>".
This is equivalent to "<% print" and "%>".
e.g. <%='selected' if $option == $current%>

=item <%h= ... %>			- HTML-escaped printing

For use inside "s, e.g. <input value="<%h=$value%>">
e.g. <%h=$name%>

=item <%hbr= ... %>			- HTML-escaped printing

For use as text in HTML documents, e.g. <p> <%hbr=$value%> </p>
e.g. <%hbr=$body_text%>

=item <%u= ... %>			- URL-escaped printing

For use inside URLs, e.g. <a href="?value=<%u=$value%>">
e.g. http://server/app?<%u=$query%>

=item <%j= ... %>			- JavaScript-escaped printing

For use with JavaScript apostrophe-quoted strings: 
e.g. <script> var v = '<%j=$value%>' </script>

=item <%include	pathname%>	- include another template

For more complex applications, other template files can be included.
The pathname is taken to be relative to the current template.
Included templates share the same protected namespace as the parent template.

=head1 NAMESPACE

Templates operate in a separate protected namespace. 
The keys from the optional hash 2nd param are used
to populate the template namespace with lexical objects of the same name.

e.g. { dom => 123 }  does  $namespace::dom = 123
e.g. { h => { dom => 123 } }  does  %namespace::h = ( dom => 123 )

Some other variables are made visible in addition to those passed:

=item $_render   - object doing this render

=head1 METHODS

=item template_dir($dir)	- root directory for template files

If passed a scalar then it is prepended to the inital template pathname.
This is not performed for included templates as they are taken to be relative
to the calling template.

=item warning(\&sub)		- how to report warnings and errors

Pass a coderef and it will be called when a warning occurs.

=item render($file, \%data)	- return template rendered using data

=cut


1;