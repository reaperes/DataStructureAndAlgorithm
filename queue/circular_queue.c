#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} Element;

typedef struct {
	Element *queue;
	int front;
	int rear;
	int capacity;
} Queue;

Queue * CreateQueue();
int IsEmpty(Queue *q);
int IsFull(Queue *q);
void EnQueue(Queue *q, Element element);
Element DeQueue(Queue *q);
void ExtendQueue(Queue *q);
void copy(Element *src, int srcStartIdx, int srcEndIdx, Element *dst, int dstStartIdx);


int main(int argc, char *argv[])
{
	Queue *q = CreateQueue();
	printf("%d\n", IsFull(q));
	
	Element e;
	e.key = 1;
	EnQueue(q, e);
	Element e2 = DeQueue(q);
	printf("%d\n", e2.key);
	
	EnQueue(q, e);
	EnQueue(q, e);
	EnQueue(q, e);
	EnQueue(q, e);
	e.key = 2;
	EnQueue(q, e);
	e2 = DeQueue(q);
	printf("%d\n", e2.key);
}

Queue * CreateQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	q->capacity = 2;
	q->queue = (Element *)malloc(sizeof(Element) * q->capacity);
	return q;
}

int IsEmpty(Queue *q)
{
	return (q->front == q->rear);
}

int IsFull(Queue *q)
{
	return (q->rear + 1) % q->capacity == q->front;
}

void EnQueue(Queue *q, Element element)
{
	if (IsFull(q)) 
		ExtendQueue(q);
	q->rear = (q->rear + 1) % q->capacity;
	q->queue[ q->rear ] = element;
}

Element DeQueue(Queue *q)
{
	if (IsEmpty(q)) {
		printf("Queue underflow error");
		exit(-1);
	}
	q->front = (q->front + 1) % q->capacity;
	return q->queue[ q->front ];
}

void ExtendQueue(Queue *q)
{
	Element *newQueue;
	newQueue = (Element *)malloc( sizeof(Element) * 2 * q->capacity );
	
	/* Copy from queue to new queue */
	int start;
	start = (q->front + 1) % q->capacity;
	if (start < 2)
		copy(q->queue, start, q->capacity - 1, newQueue, 0);
	else
	{
		copy(q->queue, start, q->capacity - 1, newQueue, 0);
		copy(q->queue, 0, q->rear, newQueue, q->capacity - start);
	}
	
	q->front = 2 * q->capacity - 1;
	q->rear = q->capacity - 1;
	q->capacity *= 2;
	free(q->queue);
	q->queue = newQueue;
}

void copy(Element *src, int srcStartIdx, int srcEndIdx, Element *dst, int dstStartIdx)
{
	int idx = 0;
	for (int i=srcStartIdx; i<=srcEndIdx; ++i)
		dst[ dstStartIdx + idx++ ] = src[i];
}
