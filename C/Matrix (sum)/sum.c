#include <stdio.h>

int main()
{
	int i, j, sumMatrix[25][25];
	int rows1, columns1,  matrix1[25][25];
	int rows2, columns2, matrix2[25][25];

	printf("Matrix - Sum \n");
	printf("Maximum Permissible Rows/Columns = 24 \n");
	printf("\n");

	printf("Rows (Matrix1) = ");
	scanf("%d", &rows1);

	printf("Columns (Matrix1) = ");
	scanf("%d", &columns1);

	if ((rows1 > 24) || (columns1 > 24)) {
		fprintf(stderr, "Rows/Columns > 24 \nAborting! \n");
		return -1;
	}

	printf("\n");

	printf("Input the Matrix1 : \n");

	for (i = 0; i < rows1; i++)
	{
		for (j = 0; j < columns1; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}

	printf("\n");

	printf("Rows (Matrix2) = ");
	scanf("%d", &rows2);

	printf("Columns (Matrix2) = ");
	scanf("%d", &columns2);

	if ((rows2 > 24) || (columns2 > 24)) {
		fprintf(stderr, "Rows/Columns > 24 \nAborting! \n");
		return -1;
	}

	printf("\n");

	printf("Input the Matrix2 : \n");

	for (i = 0; i < rows2; i++)
	{
		for (j = 0; j < columns2; j++)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}

	printf("\n");

	if (rows1 != rows2 || columns1 != columns2) {
		fprintf(stderr, "Rows/Columns of 2 Matrices Not Equal \nAborting! \n");
		return -1;
	}

	printf("Matrix1: \n");
		for (i = 0; i < rows1; i++)
		{
			for (j = 0; j < columns1; j++) {
			printf("%d	", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("Matrix2: \n");
	for (i = 0; i < rows2; i++)
	{
		for (j = 0; j < columns2; j++) {
			printf("%d	", matrix2[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("Sum: \n");
	for (i = 0; i < rows1;  i++) {
		for (j = 0; j < columns1; j++) {
			sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
			printf("%d	", sumMatrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}
