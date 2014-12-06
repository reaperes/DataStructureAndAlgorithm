#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void quick_sort(int *arr, int p, int r);
int partition(int *arr, int p, int r);
void swap(int *a, int *b);


int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int arr[10] = {1, 3, 5, 7, 9, 0, 8, 6, 4, 2};
		
	for (int i=0; i<10; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	quick_sort(arr, 0, 9);
	
	for (int i=0; i<10; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}

void quick_sort(int *arr, int p, int r)
{
	int q;
	
	if (p < r)
	{
		q = partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

int partition(int *arr, int p, int r)
{
	int pivot_idx = p + rand() % (r - p + 1);
	int pivot = arr[pivot_idx];
	int end_of_low_block = p - 1;
	int cur_idx;

	swap( &arr[r], &arr[pivot_idx] );
	
	for (cur_idx = p; cur_idx < r; ++cur_idx)
		if (arr[cur_idx] <= pivot)
			swap( &arr[++end_of_low_block], &arr[cur_idx] );

	swap( &arr[end_of_low_block+1], &arr[cur_idx] );
	return end_of_low_block + 1;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
