#include <stdio.h>
#include <stddef.h>


void multiply(int *A, int row_A, int col_A,
			int *B, int row_B, int col_B,
			int *C)
{
	int i, j, k;
	
	for (i=0; i<row_A; ++i)
		for (j=0; j<col_B; ++j)
			for (k=0; k<col_A; ++k)
				C[i*col_A + j] += A[i*col_A + k] * B[k*col_B + j];
}

int main(int argc, char *argv[]) {
	int A[3][2] = {
		{1, 2},
		{3, 4},
		{5, 6}
	};
	
	int B[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	
	int C[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	
	multiply(A, 3, 2, B, 2, 3, C);
	
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}
