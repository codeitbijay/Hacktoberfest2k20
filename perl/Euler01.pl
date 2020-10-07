#!env perl
# Compact solution to the 1st project Euler problem, in perl

$s+=$_%3*$_%5?0:$_ for 1..<>;say$s
# or
map{$s+=$_%3*$_%5?0:$_}1..<>;say$s

# Input from file, herestring, or STDIN. eg:
# perl -E 'map{$s+=$_%3*$_%5?0:$_}1..<>;say$s' <<< "999"
