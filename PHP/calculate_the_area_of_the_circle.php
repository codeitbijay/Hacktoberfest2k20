<?php

function calculate($rad)
{
    $pi = pi();
    return $pi * (pow($rad, 2));
}

echo "///// Calculate Area of The Circle /////\n\n";
echo "Insert the radius of circle = ";
$rad = trim(fgets(STDIN));
$area = calculate($rad);
echo "\n\nYour circle's radius is $rad\n";
echo "\nAnd your circle's area is $area";
echo (pow($rad, 2));
