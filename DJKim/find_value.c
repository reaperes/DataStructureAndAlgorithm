#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 정수의 랜덤 배열에서 어떠한 값이 주어졌을 때 배열 안의 두수로 그 값을 만들 수 있으면 1
// 만들 수 없으면 0 을 리턴하여라

void swap(int *a, int *b);
void quick_sort(int *arr, int left, int right);
int partition(int *arr, int start, int end);

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

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int *arr, int left, int right)
{
	int flag;
	
	if (left < right)
	{
		flag = partition(arr, left, right);
		quick_sort(arr, left, flag-1);
		quick_sort(arr, flag+1, right);
	}
}

int partition(int *arr, int start, int end)
{
	int pivot_idx = start + rand() % (end - start + 1);
	int pivot = arr[pivot_idx];
	int end_of_low_block = start - 1;
	int cur_idx;
	
	swap( &arr[end], &arr[pivot_idx] );
	
	for (cur_idx = start; cur_idx < end; ++cur_idx)
	{
		if (arr[cur_idx] <= pivot)
		{
			++end_of_low_block;
			swap( &arr[end_of_low_block], &arr[cur_idx] );
		}
	}
	swap( &arr[end_of_low_block+1], &arr[cur_idx] );
	return end_of_low_block + 1;
}
