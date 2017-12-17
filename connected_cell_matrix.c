#include <stdio.h>
#include <stdlib.h>

int ** create2dmatrix(int, int);
void enterDataMatrix(int **, int, int);
int findMaxBlock(int **, int, int);
int checkConnectedCell(int **, int, int, int, int);

int main()
{
	int **matrix, rows, colomns, max;

	printf("Enter number of rows in a matrix\n");
	scanf("%d", &rows);
	printf("Enter number of colomnss in a matrix\n");
	scanf("%d", &colomns);

	matrix = create2dmatrix(rows, colomns);
	enterDataMatrix(matrix, rows, colomns);

	max = findMaxBlock(matrix, rows, colomns);
	printf("Number of cell connect is/are %d\n", max);
	return 0;
}

int ** create2dmatrix(int rows, int colomns)
{
	int val1, **matrix;
	matrix = (int **)malloc(sizeof(int *)*rows);
	for (val1 = 0; val1 < rows; val1++){
			*(matrix + val1) = (int *)malloc(sizeof(int)*colomns);
	}

	return matrix;
}

void enterDataMatrix(int **matrix, int rows, int colomns)
{
	int val, val1;
	for (val = 0; val < rows; val++){
		for (val1 = 0; val1 < colomns; val1++){
			printf("enter the data in %d row and %d colomn\n", val, val1);
			scanf("%d", (*(matrix + val) + val1));
		}
	}
}
int findMaxBlock(int **matrix, int rows, int colomns)
{
	int maxNumber = 0, val, val1;
	for (val = 0; val < rows; val++){
		for (val1 = 0; val1 < colomns; val1++){
			if (*(*(matrix + val) + val1) == 1){
				maxNumber = maxNumber + checkConnectedCell(matrix, rows, colomns, val, val1);
			}
		}
	}
	return maxNumber;
}

int checkConnectedCell(int **matrix, int rows, int colomns, int val, int val1)
{
	if (val > rows || val1 > colomns)
		return 0;
	int count;
	int direction[][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
	for (count = 0; count < 8; count++){
		int newR = val + direction[count][0];
		int newC = val1 + direction[count][1];
		if (newR >= 0 && newR < rows && newC >= 0 && newC < colomns){
			printf("----------------- %d %d\n", newR, newC);
			if (*(*(matrix + newR) + newC) == 1)
				return 1;
		}
	}
	return 0;
}
