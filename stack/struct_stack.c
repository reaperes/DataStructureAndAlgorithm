#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} Element;

typedef struct {
	Element *stack;
	int top;
	int capacity;
} Stack;

Stack * CreateStack();
void Print(Stack *s);
int IsEmpty(Stack *s);
int IsFull(Stack *s);
void Push(Stack *s, Element element);
void ExtendStack(Stack *s);
Element Pop(Stack *s);


int main(int argc, char *argv[])
{
	Stack *s = CreateStack();
	Print(s);
	
	Element e1;
	Element e2;
	Element e3;
	
	e1.key = 1;
	e2.key = 2;
	e3.key = 3;

	Push(s, e1);
	Push(s, e2);
	Push(s, e3);
	Print(s);
	
	Element e = Pop(s);
	printf("==> %d\n", e.key);
	Print(s);
	
	e = Pop(s);
	printf("==> %d\n", e.key);
	e = Pop(s);
	printf("==> %d\n", e.key);
	e = Pop(s);
	printf("==> %d\n", e.key);
}

Stack * CreateStack()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
	s->capacity = 1;
	s->stack = (Element *)malloc(sizeof(Element) * s->capacity);
	for (int i=0; i<s->capacity; ++i)
		(s->stack + i)->key = 0;
	return s;
}

void Print(Stack *s)
{
	if (IsEmpty(s))
		printf("Empty stack\n");
	
	for (int i=s->top; i>=0; --i)
		printf("%d\n", (s->stack+i)->key);
}

int IsEmpty(Stack *s)
{
	return s->top < 0;
}

int IsFull(Stack *s)
{
	return s->top >= s->capacity - 1;
}

void Push(Stack *s, Element element)
{
	if (IsFull(s))
		ExtendStack(s);
	s->stack[++(s->top)] = element;
}

void ExtendStack(Stack *s)
{
	s = realloc(s, 2 * s->capacity * sizeof(Element));
	s->capacity *= 2;
}

Element Pop(Stack *s)
{
	if (IsEmpty(s))
	{
		printf("Underflow error occured.");
		exit(-1);
	}
	return s->stack[ s->top-- ];
}