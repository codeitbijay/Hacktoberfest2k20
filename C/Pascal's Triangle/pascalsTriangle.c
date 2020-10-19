#include <stdio.h>

long int iterativeFactorial(long int input);

int main()
{
	long int number, fact1, fact2, fact3;

	printf("Pascal's Triangle \n");
	printf("\n");

	printf("Enter a Whole Number (max. 12): ");
	scanf("%ld", &number);
	printf("\n");

	if (number > 12) {
		printf("Number > 12 \n");
		printf("\n");
		return 1;
	}

	for (int i = 0; i <= number; i++) {
		fact1 = iterativeFactorial(i);

		for (int j = number; j > i; j--) {
			printf("   ");
		}

		for (int j = 0; j <= i; j++) {
			int k;
			k = i - j;
			fact2 = iterativeFactorial(k);
			fact3 = iterativeFactorial(j);

			//Binomial Coefficient
			printf("%03ld   ", (fact1 / (fact2*fact3)));
		}
		printf("\n");
	}

	printf("\n");

	return 0;
}

long int iterativeFactorial(long int input)
{
	int factorial = 1;

	for (int i = 1; i <= input; i++) {
		factorial *= i;
	}

	return factorial;
}