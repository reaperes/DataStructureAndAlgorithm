#include <stdio.h>

/*
	Input  : Int Array
	Output : Int Array - each index value is average which from 0 to index itself
*/

void average(int *arr, size_t len, float *avg)
{
	int i, sum = 0;
	
	for (i=0; i<len; ++i)
	{
		sum += arr[i];
		avg[i] = (float)sum / (i+1);
	}
}

int main(int argc, char *argv[]) {
	int arr[5] = {1, 2, 3, 4, 5};
	float avg[5] = {0};
	
	average(arr, 5, avg);
	
	for (int i=0; i<5; ++i)
		printf("%.2f ", avg[i]);
}