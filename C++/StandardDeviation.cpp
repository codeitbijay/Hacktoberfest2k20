/*
	program to calculate the Standard Deviation using direct method
*/

#include<stdio.h>
#include<math.h>

double mean(int a[], int n){
	double sum = 0.0;
	for(int i = 0; i < n; i++)
		sum = sum + a [i];

	return sum/n;
}

double standardDeviation(int a[], int n) {

	// calling mean function to calculate the mean of the whole array
	double x = mean(a, n);

	// replace each array element with its difference from the mean
	for(int i = 0; i < n; i++)
		a[i] = a[i] - x;


	double sum = 0.0;
	for(int i = 0; i < n; i++)
		sum = sum + (1.0 * a[i] * a[i]);

	sum = sum/n;

	return sqrt(sum);
}

int main(){

	int a[] = {25, 40, 38, 67, 92, 48, 73, 55, 63, 71};
	int n = sizeof(a) / sizeof(int);

	double sd = standardDeviation(a, n);

	printf("%lf ", sd);

	return 0;
}
