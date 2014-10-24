#include <stdio.h>
#include <stdlib.h>


void print2DArray(int **arr, int n, int m);
int ** make2DArray(int rows, int cols);
int matrixSum(int **result, int **A, int **B, int rowNum, int colNum);
int matrixMulti(int **result,
				    int **matrixA, int rowNumOfA, int colNumOfA,
					 int **matrixB, int rowNumOfB, int colNumOfB);
int matrixTranspose(int **matrixA_T, int **matrixA, int rowNum, int colNum);

int main(int argc, char *argv[]) {
	int **A = make2DArray(3, 3);
	int **B = make2DArray(3, 3);
	int **result = make2DArray(3, 3);
	
//	A = {
//		0, 0, 1,
//		1, 0, 1,
//		0, 1, 0
//	};
	
	A[0][2] = 1;
	A[1][0] = 1;
	A[1][2] = 1;
	A[2][1] = 1;
	
//	B = {
//		1, 1, 1,
//		1, 0, 1,
//		1, 1, 1
//	};

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			B[i][j] = 1;
	B[1][1] = 0;
	
	print2DArray(A, 3, 3);
	print2DArray(B, 3, 3);
	
	int sum = matrixSum(result, A, B, 3, 3);
	printf("===== Sum =====\n");
	print2DArray(result, 3, 3);
	
	matrixMulti(result, A, 3, 3, B, 3, 3);
	printf("===== Multi =====\n");
	print2DArray(result, 3, 3);
	
	printf("===== Transpose =====\n");
	int **matrixA_T = make2DArray(3, 3);
	matrixTranspose(matrixA_T, A, 3, 3);	print2DArray(matrixA_T, 3, 3);
}

int ** make2DArray(int rows, int cols)
{
	int **arr = (int**)malloc(sizeof(int*) * rows);
	
	for (int i=0; i<rows; ++i)
		arr[i] = (int *)malloc(sizeof(int) * cols);
	
	return arr;
}

int matrixSum(int **result, int **A, int **B, int rowNum, int colNum)
{
	int sum = 0;
	
	for (int i=0; i<rowNum; ++i)
		for (int j=0; j<colNum; ++j)
			sum += result[i][j] = A[i][j] + B[i][j];
	return sum;
}

void print2DArray(int **arr, int n, int m)
{
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<m; ++j)
			printf("%d", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

int matrixMulti(int **result,
	   			 int **matrixA, int rowNumOfA, int colNumOfA,
					 int **matrixB, int rowNumOfB, int colNumOfB) {
	if (colNumOfA != rowNumOfB)
		return -1;
		
	for (int i=0; i<rowNumOfA; ++i)
	{
		for (int j=0; j<colNumOfB; ++j)
		{
			result[i][j] = 0;
			for (int k=0; k<colNumOfA; ++k)
				result[i][j] += matrixA[i][k] * matrixB[k][j];
		}
	}
	return 0;
}

int matrixTranspose(int **matrixA_T, int **matrixA, int rowNum, int colNum)
{
	for (int i=0; i<rowNum; ++i)
		for (int j=0; j<colNum; ++j)
			matrixA_T[j][i] = matrixA[i][j];
	return 0;
}