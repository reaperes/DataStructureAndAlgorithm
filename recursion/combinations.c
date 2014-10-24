#include <stdio.h>

/* 문제
	n 개의 문자로 구성된 문자열이 주어져 있을 때 길이가 1이상 이고, n 보다 작거나 같은
	모든 조합을 출력하는 함수를 만들어라.
*/

/* Idea
	{a, b, c} 일 때, Combination 이면 
	{}, {a}, {b}, {c}, {a, b}, {a, c}, {b, c}, {a, b, c} 이다.
	이는 000, 100, 010, 001, 110, 101, 011, 111에 매핑될 수 있다.
*/

/* Pseudo code
	def comb(list, len, start):
		if start == len:
			return print array
		list(i) = 0
		comb(list, len, start+1)
		list(i) = 1
		comb(list, len, start+1)
*/

void printComb(int *list, char *trans, int len);
void comb(int *list, char *trans, int len, int start);


int main(int argc, char *argv[]) {
	char trans[] = {'a', 'b', 'c', 'd', 'e'};
	int list[] = {0, 0, 0, 0, 0};
	const int len = 5;
	
	comb(list, trans, len, 0);
	return 0;
}

void comb(int *list, char *trans, int len, int start)
{
	if (len == start + 1)
		return printComb(list, trans, len);
	list[start] = 0;
	comb(list, trans, len, start+1);
	list[start] = 1;
	comb(list, trans, len, start+1);
}

void printComb(int *list, char *trans, int len)
{
	for (int i=0; i<len; ++i)
		if (list[i] == 1)
			printf("%c", trans[i]);
	printf("\n");
}
