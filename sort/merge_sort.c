#include <stdio.h>


void copy(int *src, int len, int *dst);
void sort(int arr[], int clone[], int start, int end);
void merge(int arr[], int clone[], int firstBegin, int firstLast, int secondLast);
void print(int arr[], int start, int end);

int main(int argc, char *argv[]) {
	int arr[] = {4, 2, 6, 100, 42};
	int len = 5;
	int clone[len];
	copy(arr, len, clone);

	sort(arr, clone, 0, len-1);
	print(arr, 0, len-1);
}

void sort(int arr[], int clone[], int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		sort(arr, clone, start, mid);
		sort(arr, clone, mid+1, end);
		merge(arr, clone, start, mid, end);
		copy(arr, 5, clone);
	}
}

void merge(int arr[], int clone[], int firstBegin, int firstLast, int secondLast)
{
	int idx, arr1Idx, arr2Idx;
	
	arr1Idx = firstBegin;
	arr2Idx = firstLast + 1;
	
	for (idx = firstBegin; idx <= secondLast; ++idx)
	{
		if ( arr1Idx > firstLast )
			arr[idx] = clone[arr2Idx++];
		else if ( arr2Idx > secondLast )
			arr[idx] = clone[arr1Idx++];
		else if ( clone[arr1Idx] < clone[arr2Idx] )
			arr[idx] = clone[arr1Idx++];
		else
			arr[idx] = clone[arr2Idx++];
	}
}

void copy(int *src, int len, int *dst)
{
	for (int i=0; i<len; ++i)
		dst[i] = src[i];
}

void print(int arr[], int start, int end)
{
	for (int i=start; i<=end; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}