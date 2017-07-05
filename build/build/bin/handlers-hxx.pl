#!/usr/bin/perl -w

use strict;

use FindBin;
use lib "$FindBin::Bin/../contrib";

die("usage: $FindBin::Script handler.hxx [ handler.hxx ... ]\n") unless @ARGV;

print <<'__HXX__';
#ifndef HANDLERS_HXX_
#define HANDLERS_HXX_

__HXX__

print join('', map { qq{#include "$_"\n} } @ARGV );

print <<'__HXX__';

#endif
__HXX__
