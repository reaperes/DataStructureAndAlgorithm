#include <stdio.h>

/* Problem definition
	Given a set of n >= 1 elements, point out all possible permutations of this set
*/

/* Pseudo code
	void perm(char[] list, int len)
		for i := 0; i < len - 1; i++
			for j := i+1; j < len; j++
				swap( &(list[i]), &(list[j]) )
				print_array( list )
				swap( &(list[i]), &(list[j]) )
*/


void perm(char *list, int start, int end);
void swap(char *a, char *b);


int main(int argc, char *argv[]) {
	char list[] = {'a', 'b', 'c', 'd', 'e'};
	perm(list, 0, 4);
}

void perm(char *list, int start, int end)
{
	int pos;

	if (start == end)
	{
		for (pos = 0; pos <= end; ++pos)
			printf("%c", *(list+pos));
		printf("\n");
	}
	else
	{
		for (pos = start; pos <= end; ++pos)
		{
			swap( &(list[start]), &(list[pos]) );
			perm(list, start + 1, end);
			swap( &(list[start]), &(list[pos]) );
		}
	}
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
