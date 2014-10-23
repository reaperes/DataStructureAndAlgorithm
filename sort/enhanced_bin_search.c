#include <stdio.h>

/*
	주어진 상황
		n 개의 숫자가 배열 list 에 오름차순으로 정렬 되어 저장되어 있다고 가정하자.
		즉, list[0] <= list[1] <= ... <= list[n-1] 라고 가정하자.
			예) {1, 3, 8, 8, 8, 8, 8, 10, 25, 30}
		
	문제
		1) 정수 key 가 주어지면 주어진 key가 이 배열에 있는지 없는지를 검사하고 있다면 같은 값 중
		가장 왼쪽에 있는 값의 위치를 반환하는 C 함수 코딩
		2) 같은 값 중 가장 오른쪽에 있는 값의 위치를 반환하는 C 함수 코딩
		3) key 와 값이 같은 원소의 개수를 반환하는 C 함수 코딩
*/

/* Pseudo code
	int enhanced_bin_search(int *list, int n, int key)
		idx := -1;
		while (there are more integers to check):
			mid = (left + right) / 2;
			if list[mid] == key:
				idx = right = mid - 1
			if key < list[mid]:
				right = mid - 1
			if list[mid] < key:
				left = mid + 1
		return idx
*/


int bin_search_left_index(int *list, int left, int right, int key);
int bin_search_right_index(int *list, int left, int right, int key);
int bin_search_num(int *list, int left, int right, int key);


int main(int argc, char *argv[]) {
	int list[] = {1, 3, 8, 8, 8, 8, 8, 10, 25, 30};
	int key = 8;
	int left_idx = bin_search_left_index(list, 0, 9, key);
	int right_idx = bin_search_right_index(list, 0, 9, key);
	int num = bin_search_num(list, 0, 9, key);
	printf("list[%d] = %d, %d is the most left index.\n", left_idx, list[left_idx], left_idx);
	printf("list[%d] = %d, %d is the most right index.\n", right_idx, list[right_idx], right_idx);
	printf("Number of key %d is %d", key, num);
}

int bin_search_left_index(int *list, int left, int right, int key)
{
	int idx = -1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (list[mid] < key)
			left = mid + 1;
		else if (list[mid] > key)
			right = mid - 1;
		else {
			right = mid - 1;
			idx = mid;
		}
	}
	return idx;
}

int bin_search_right_index(int *list, int left, int right, int key)
{
	int idx = -1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (list[mid] < key)
			left = mid + 1;
		else if (list[mid] > key)
			right = mid - 1;
		else {
			left = mid + 1;
			idx = mid;
		}
	}
	return idx;
}

int bin_search_num(int *list, int left, int right, int key)
{
	int left_idx = bin_search_left_index(list, left, right, key);
	if (left_idx == -1) return 0;
	int right_idx = bin_search_right_index(list, left, right, key);
	return right_idx - left_idx + 1;
}