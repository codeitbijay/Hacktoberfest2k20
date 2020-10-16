#include <stdio.h>

int main() {
	printf("Fibonacci Series \n");
	printf("\n");

	int i, number;
	int first, second, third;

	printf("Number of Terms (max. 16): ");
	scanf("%d", &number);
	printf("\n");

	//limiting the Fibonacci Series
	number = (number > 16 ? 16 : number);

	if (number < 0) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	first = 0;
	second = 1;

	if (number >= 0) {
		printf("fib(0)\t: %d \n", first);
	}
	if (number >= 1) {
		printf("fib(1)\t: %d \n", second);
	}

	for (i = 2; i <= number; i++) {
		third = first + second;

		printf("fib(%d)\t: %d \n", i, third);

		first = second;
		second = third;
	}
	printf("\n");
	printf("\n");

	return 0;
}