#!/usr/bin/perl

use LWP::UserAgent;

die("usage: vanitygen.pl server suffix\n") unless @ARGV == 2;

my ($server, $suffix) = @ARGV;
my $url = "http://$server:8125/burst";
my $len = length($suffix);

my $ua = new LWP::UserAgent;

open(DICT, '/usr/share/dict/words') || die("Can't open /usr/share/dict/words: $!\n");
my @words = <DICT>;
close(DICT);
chomp @words;

$| = 1;

while(1) {
	my @secret;
	for(my $i=0; $i<rand()*10; $i++) {
		push(@secret, $words[rand()*@words]);
	}

	my $payload = "requestType=getAccountId&secretPhrase=" . join(' ', @secret);

	my $response = $ua->post($url, Content => $payload);
	my $content = $response->content;

	my $address = substr($content, index($content, 'ccountRS') + 17, 20);
	#print "\r$address";

	if ( substr($address, 0 - $len) eq $suffix ) {
		print "$address\n", join(' ', @secret), "\n\n";
	}
}
