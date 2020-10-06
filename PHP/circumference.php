<?php

function calculate($rad)
{
    $pi = pi();
    return 2 * $pi * $rad;
}

echo "///// Calculate circumference /////\n\n";
echo "Insert the radius of circle = ";
$rad = trim(fgets(STDIN));
$circumference = calculate($rad);
echo "\n\nYour circle's radius is $rad\n";
echo "\nAnd your circumference is $circumference";
