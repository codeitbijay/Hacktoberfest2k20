#include <stdio.h>
long int iterativeFactorial(long int input);
int main() {
	long int number, result;

	printf("Factorial of a number : \n");
	printf("\n");

	printf("Enter a Whole Number (max. 12) : \n");
	scanf("%ld", &number);
	printf("\n");

	if (number > 12){
		printf("Number > 12 \n");
		printf("\n");
		return 1;
	}
	result = iterativeFactorial(number);
	if (result == -1){
		printf("Invalid Input!! \n");
	}
	else{
		printf("(%ld)! = %ld \n", number, result);
	}
	printf("\n");
	return 0;
}

long int iterativeFactorial(long int input)
{
	int factorial = 1;
	for (int i = 1; i <= input; i++){
		factorial *= i;
	}
	return factorial;
}
