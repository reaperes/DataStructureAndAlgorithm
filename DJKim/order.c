#include <stdio.h>

// 오름차순으로 정렬된 배열에서 같은 키가 몇개가 있는지 찾아라.

int binary_search(int *arr, int start, int end, int key)
int find_key(int *arr, size_t len, int key);


int main(int argc, char *argv[]) {
	int arr[20] = {
		1, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 5
	};
	
	printf("%d\n", find_key(arr, 20, 3));
}

int binary_search(int *arr, int start, int end, int key)
{
	int mid;
	
	if (start > end)
		return -1;
	
	mid = start + (end - start) / 2;
	
	if ( key < arr[mid] )
		return binary_search(arr, start, mid - 1, key);
	else if ( arr[mid] < key )
		return binary_search(arr, mid + 1, end, key);
	else /* arr[mid] == key */
		return mid;
}

int find_key(int *arr, size_t len, int key)
{
	int find_idx, left_idx, right_idx;
	int temp;
	
	find_idx = binary_search(arr, 0, len-1, key);
	if (find_idx == -1)
		return 0;	// if not exists key

	temp = left_idx = right_idx = find_idx;
	
	// find the leftist index
	while (1)
	{
		temp = binary_search(arr, 0, temp-1, key);
		if (temp == -1)
			break;
		left_idx = temp;
	}

	// find the rightist index
	while (1)
	{
		temp = binary_search(arr, temp+1, len-1, key);
		if (temp == -1)
			break;
		right_idx = temp;
	}
	
	return right_idx - left_idx + 1;
}
