#include <stdio.h>

#define LEFT(i) i<<1
#define RIGHT(i) (i<<1) + 1
#define PARENT(i) i>>1

void buildMaxHeap(int arr[]);
void swap(int *a, int *b);
void maxHeapify(int arr[], int idx);

#define HEAPSIZE(A)	10
int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

int main(int argc, char *argv[]) {
	buildMaxHeap(A);
}

void buildMaxHeap(int arr[])
{
    int i, z;
    z = HEAPSIZE(arr);
    printf("Total heap: %d\n", z);
 
    for ( i = z / 2; i < z + 1; ++i)
    {
        printf("I: %d\n", i);
        maxHeapify(arr, i);
        printf("Executed correctly.\n");
    }
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int arr[], int idx)
{
	int l = LEFT(idx);
	int r = RIGHT(idx);
	int largest = idx;

	if ( l <= HEAPSIZE(arr) && arr[l] > arr[idx] )
		largest = l;
	
	if ( r <= HEAPSIZE(arr) && arr[r] > arr[largest] )
		largest = r;
		
	if ( largest != idx )
	{
		swap( &arr[idx], &arr[largest]);
		maxHeapify(arr, largest);
	}
}		
