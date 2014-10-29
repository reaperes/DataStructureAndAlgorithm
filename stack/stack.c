#include <stdio.h>
#include <stdlib.h>

/* Stack ADT

	Stack CreateStack(maxStackSize) := 
		create an empty stack whose maximum size is maxStackSize
	
	Boolean IsFull(stack, maxStackSize):
		if number of elements in stack == maxStackSize:
			return True
		else:
			return False
	
	Stack Push(stack, item):
		if IsFull(stack) stackFull
		else insert item into top of stack and return
		
	Boolean IsEmpty(stack):
		if (stack is empty) return TRUE
		else return FALSE
		
	Element Pop(stack):
		if (IsEmpty(stack)) return
		else remove and return the item at the top of the stack
*/

#define MAX_STACK_SIZE 100

typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
} Stack;

Stack * CreateStack();
void Print(Stack *s);
int IsEmpty(Stack *s);
int IsFull(Stack *s);
void Push(Stack *s, int item);
int Pop(Stack *s);


int main(int argc, char *argv[])
{
	Stack *s = CreateStack();
	Print(s);

	Push(s, 0);
	Push(s, 1);
	Push(s, 2);
	Print(s);
	
	Pop(s);
	Print(s);
}

Stack * CreateStack()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
	return s;
}

void Print(Stack *s)
{
	if (IsEmpty(s))
		printf("Empty stack\n");
	
	for (int i=s->top; i>=0; --i)
		printf("%d\n", s->stack[i]);
}

int IsEmpty(Stack *s)
{
	return s->top < 0;
}

int IsFull(Stack *s)
{
	return s->top >= MAX_STACK_SIZE - 1;
}

void Push(Stack *s, int item)
{
	if (IsFull(s))
		return;
	s->stack[++(s->top)] = item;
}

int Pop(Stack *s)
{
	if (IsEmpty(s))
	{
		printf("Underflow error occured.");
		exit(-1);
	}
	
	return s->stack[ (s->top)-- ];
}