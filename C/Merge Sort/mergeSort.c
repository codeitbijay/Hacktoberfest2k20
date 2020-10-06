#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);

int main() {
	printf("Merge Sort \n");
	printf("\n");

	int i, n;

	printf("Total Elements : ");
	scanf("%d", &n);
	printf("\n");

	if (n < 1) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	int *A = (int *)calloc(n, sizeof(int));

	printf("Unsorted Input \n");
	for (i = 0; i < n; i++) {
		scanf("%d", (A + i));
	}
	printf("\n");

	mergeSort(A, 0, (n-1));

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

void merge(int *A, int p, int q, int r) {
	int i, j;
	int m = q - p + 1;
	int n = r - q;

	int *left = (int *)calloc(m + 1, sizeof(int));
	int *right = (int *)calloc(n + 1, sizeof(int));

	for (i = 0; i < m; i++) {
		*(left + i) = *(A + (p + i));
	}
	for (j = 0; j < n; j++) {
		*(right + j) = *(A + (q + j + 1));
	}

	*(left + m) = INT_MAX;
	*(right + n) = INT_MAX;

	i = j = 0;

	for (int k = p; k <= r; k++) {
		if (*(left + i) <= *(right + j)) {
			*(A + k) = *(left + i);
			i++;
		}
		else {
			*(A + k) = *(right + j);
			j++;
		}
	}
}

void mergeSort(int *A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, (q + 1), r);
		merge(A, p, q, r);
	}
}