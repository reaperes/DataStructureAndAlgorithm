#include <stdio.h>

//void sort(int[] arr):
//	for curPos = 1 To arr.length - 1:
//		for idx = 0 To curPos - 1:
//			if compare( arr[curPos], arr[idx] )
//				swap ( &arr[curPos], &arr[idx] )
//			
//int compare(int *a, int *b)
//	if (*a < *b)
//		return 1
//	return 0

void print(int arr[], int len);
void swap(int *a, int *b);
int compareA(int *a, int *b);
void sort(int arr[], int len, int (*func)(int *, int *) );

int main(int argc, char *argv[]) {
	int arr[10] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
	print(arr, 10);
		
	sort(arr, 10, &compareA);
	print(arr, 10);
		
	sort(arr, 10, &compareB);
	print(arr, 10);
}

void print(int arr[], int len)
{
	for (int i=0; i<len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void sort(int arr[], int len, int (*func)(int *, int *) )
{
	int idx, compareIdx;
	
	for (idx = 1; idx < len; ++idx)
		for (compareIdx = 0; compareIdx < idx; ++compareIdx)
			if ( ( *func )( &arr[idx], &arr[compareIdx] ) )
				swap( &arr[idx], &arr[compareIdx] );
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int compareA(int *a, int *b)
{
	return (*a < *b);
}

int compareB(int *a, int *b)
{
	return (*a > *b);
}