#include <stdio.h>

int array[15] = {10, 7, 5, 4, 3, 3, 6, 9, 11, 7, 5, 4, 8, 10, 12};


void find(int *arr, size_t len, int *result)
{
	int i, idx, rst_idx, lowest_first_idx;

	rst_idx = 0;


	idx = 1;
	while (idx < len)
	{
		lowest_first_idx = idx-1;
		for (; idx < len; ++idx)
		{
			if (arr[idx-1] < arr[idx])
				break;
			
			if (arr[lowest_first_idx] > arr[idx])
			{
				lowest_first_idx = idx;
				continue;
			}
		}
		
		if (idx < len)
			for (i=lowest_first_idx; i<idx; ++i)
				result[rst_idx++] = i;
			
		for (; idx < len; ++idx)
			if (arr[idx-1] > arr[idx])
				break;
	}
}

int main(int argc, char *argv[]) {
	int i = 0;
	int result[15] = {0};
	
	find(array, 15, result); 
	
	for (i=0; i<15; ++i)
		printf("%d ", result[i]);
	printf("\n");
}
