#include <stdio.h>

/* 문제
	서로 다른 n 개의 숫자가 배열 list 에 오름차순으로 정렬되어 있다고 가정하자.
	즉, list[0] < list[1] < ... < list[n-1] 라고 가정하자.
		예) list 1, 3, 8, 10, 12, 14, 15, 19, 25, 30
	정수 key가 주어지면 주어진 key가 이 배열에 있는지 없는지를 검사하라.
	결과 출력
		만약 list[i] = key 인 i 가 있다면 i 를 return 한다.
		key 가 배열에 존재하지 않으면 -1 을 return 한다.
*/

/* Pseudo code
	while (there are more integers to check) {
		mid = (left + right) / 2;
		if (key == mid)
			return mid
		else if (key < mid)
			right = mid - 1
		else
			left = mid + 1
	}
*/


int bin_search(int *list, int n, int key);
int _bin_search(int *list, int key, int left, int right);


int main(int argc, char *argv[]) {
	int list[] = {1, 3, 8, 10, 12, 14, 15, 19, 25, 30};
	int key = 25;
	int idx = bin_search(list, 10, key);
	printf("list[%d] = %d\n", idx, key);
}

int bin_search(int *list, int n, int key) {
	return _bin_search(list, key, 0, n-1);
}

int _bin_search(int *list, int key, int left, int right)
{
	int mid;
	
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (key < list[mid])
			right = mid - 1;
		else if (key > list[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}