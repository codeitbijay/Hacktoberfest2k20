#include <stdio.h>

int main()
{
	int i, j, rows, columns, matrix[25][25], scaler;

	printf("Matrix - Scaler Multiplication \n");
	printf("Maximum Permissible Rows/Columns = 24 \n");
	printf("\n");

	printf("Rows = ");
	scanf("%d", &rows);

	printf("Columns = ");
	scanf("%d", &columns);

	if ((rows > 24) || (columns > 24)) {
		fprintf(stderr, "Rows/Columns > 24 \nAborting! \n");
		return -1;
	}

	printf("\n");

	printf("Input the Matrix: \n");

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("\n\nMatrix: \n");
	for (i = 0; i < rows; i++)
	{

		for (j = 0; j < columns; j++)
		{
			printf("%d	", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("Scaler λ = ");
	scanf("%d", &scaler);

	printf("\nScaler Multiplication: \n");
	for (i = 0; i < rows; i++)
	{

		for (j = 0; j < columns; j++)
		{
			matrix[i][j] *= scaler;
			printf("%d	", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}