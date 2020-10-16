<?php   
//PHP code to get the Fibonacci series
//In this example we'll see two ways: recursive and iterative



//The definition of recursive function:
function recFibonacci($number){ 
    //If the input is 0 or 1, just return it:
    if ($number == 0){
        return 0;     
	}
    else if ($number == 1){
        return 1;     
	}    
    //If not, do the math:
    else{
		return (recFibonacci($number-1) + recFibonacci($number-2));
	}
} 
  
//Execute the recursive function:
echo "The recursive function result: ";
$number = 15; 
for ($i = 0; $i < $number; $i++){   
    echo recFibonacci($i).' ';
}

//Split two sections:
echo "<hr>";


//The definition of iterative function:
function iteFibonacci($num){
	//We already know that series start with 0 and 1:
    $num1 = 0; 
    $num2 = 1;
	//Keep a counter so we'll know when to stop:
    $counter = 0; 
	echo "The iterative function result:";
    while ($counter < $num){ 
        echo ' '.$num1; 
        $num3 = $num2 + $num1; 
        $num1 = $num2; 
        $num2 = $num3; 
        $counter = $counter + 1; 
    } 
} 
//Execute the iterative function:
$num = 15; 
iteFibonacci($num);
?> 

