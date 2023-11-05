<?php
// PHP code to create simple matrix alphabets

function print_alphabets($col,$row)
{
    $alpha = range('a','z');
    for ($i=1;$i<=$row;$i++)
    {
        for ($j=1;$j<=$col;$j++)
        {
            $output .= array_shift($alpha)." ";
        }
        $output = $output."\n";
    }
   return $output;
}

$column = readline("Set columns : ");
$row = readline("Set rows : ");

echo "\n" . print_alphabets($column,$rows) . "\n";

// END OF FILE
