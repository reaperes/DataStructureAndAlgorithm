#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *stack;
	int top;
	int capacity;
} Stack;

void init();
void destroy();
void print();
int is_full();
int is_empty();
void push(int key);
int pop();


Stack s;

int main(int argc, char *argv[]) {
	int i;

	init();

	for (i=0; i<5; ++i)
		push(1);
	for (i=0; i<4; ++i)
		pop();
	print();
	
	pop();
	print();
	
	destroy();
}

void init() {
	s.top = -1;
	s.capacity = 3;
	s.stack = (int *) malloc( sizeof(int) * s.capacity );
}

void destroy() {
	if (s.stack != NULL)
		free(s.stack);
}

void print() {
	int i;
	
	printf("== Stack (%d) ==\n", s.capacity);
	for (i=s.capacity-1; i>s.top; --i)
		printf("%2d |    |\n", i);

	if (is_empty()) {
		printf("   |====| <= top\n\n");
		return ;
	}
	
	printf("%2d | %2d | <= top\n", s.top, s.stack[s.top]);
	for (i=s.top-1; i>=0; --i)
		printf("%2d | %2d | \n", i, s.stack[i]);
	printf("   |====|\n\n");
}

int is_full() {
	return s.top + 1 >= s.capacity;
}

int is_empty() {
	return s.top < 0;
}

void push(int key) {
	if (is_full()) {
		s.stack = realloc(s.stack, 2 * s.capacity * sizeof(int));
		s.capacity *= 2;
	}
	s.stack[++s.top] = key;
}

int pop() {
	if (is_empty())
		exit(1);
	return s.stack[s.top--];
}