#include <stdio.h>

/* Pseudo code
	for (i=0; i<n; i++) {
		Examine list[i] to list[n-1] and suppose that
		the smallest integer is at list[min];
		
		Interchange list[i] and list[min];
	}
*/

void sort(int list[], int n);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
	int list[] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
	sort(list, 10);
	
	for (int i=0; i<10; ++i)
	{
		printf("%d ", list[i]);
	}
}

void sort(int list[], int n)
{
	int id, target_id, min_id;
	
	for (id = 0; id < n-1; ++id)
	{
		min_id = id;
		for (target_id = id + 1; target_id < n; ++target_id)
		{
			if (list[target_id] < list[min_id])
				min_id = target_id;
		}
		swap(&(list[id]), &(list[min_id]));
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
