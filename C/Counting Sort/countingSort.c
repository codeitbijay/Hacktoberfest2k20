#include <stdio.h>
#include <stdlib.h>

void countingSort(int *A, int *B, int k, int n);

int main() {
	printf("Counting Sort \n");
	printf("\n");

	int i, k, n;

	printf("Range of Input ( 0 - k ) \n");
	printf("k = ");
	scanf("%d", &k);
	printf("\n");

	if (k < 0) {
		printf("Incorrect Range \n");
		printf("\n");
		return 1;
	}

	printf("Total Elements : ");
	scanf("%d", &n);
	printf("\n");

	if (n < 1) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	int *A = (int *)calloc((n+1), sizeof(int));
	int *B = (int *)calloc((n+1), sizeof(int));

	printf("Unsorted Input \n");
	for (i = 1; i <= n; i++) {
		scanf("%d", (A + i));
		if (*(A + i)<0 || *(A + i)>k) {
			printf("Input Out of Range! \n");
			printf("\n");
			return 1;
		}
	}
	printf("\n");

	countingSort(A, B, k, n);

	printf("Sorted Output \n");
	for (i = 1; i <= n; i++) {
		printf("%d \n", *(B + i));
	}
	printf("\n");

	return 0;
}

void countingSort(int *A, int *B, int k, int n) {
	int i, j;

	int *auxiliary = (int *)calloc((k + 1), sizeof(int));

	for (j = 1; j <= n; j++) {
		auxiliary[A[j]]++;
	}

	for (i = 1; i <= k; i++) {
		auxiliary[i] = auxiliary[i] + auxiliary[i - 1];
	}

	for (j = n; j > 0; j--) {
		B[auxiliary[A[j]]] = A[j];
		auxiliary[A[j]]--;
	}
}