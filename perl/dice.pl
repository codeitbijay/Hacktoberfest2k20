#!/usr/bin/perl
use strict;
use warnings;

my $input = "4d6"; # replace with shift to take input from STDIN

my ($count,$sides) = split(/d/,$input);
my @results;

for (1..$count) {
    push @results, int(rand($sides)+1)
}


#OUTPUT

# Print Numbers
print join(" ",@results);

# Print Sum
my $sum = 0;
$sum += $_ for @results;

print " - Sum: ", $sum;
