#!env perl
// Converts a number up to 3999 to roman numerals

use strict;
use warnings;

my $input = shift;
die("Number must be between 1 and 3999") unless $input < 4000;

my @romans = qw(N I V X L C D M);
my @digits = split(//, reverse($input), 4);

my @r;

my $i = 1;
foreach my $digit (@digits) {
    if($digit == 4 || $digit == 9) {
        push @r, ($digit == 4) ? $romans[$i+1] : $romans[$i+2];
        push @r, $romans[$i];
    } elsif($digit >= 5) {
        push @r, $romans[$i] x ($digit-5);
        push @r, $romans[$i+1];
    } elsif($digit == 10) {
        push @r, $romans[$i+2];
    } else {
        push @r, $romans[$i] x $digit;
    }
    $i+=2;
}

print reverse @r;
