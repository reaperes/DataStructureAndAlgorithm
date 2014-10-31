#include <stdio.h>
#include <stdlib.h>

/* Queue (A finite ordered list with zero or more elements)

	Queue CreateQ(maxQueueSize):
		create an empty queue whose maximum size is maxQueueSize
		
	Boolean IsFull(queue, maxQueueSize):
		if (number of elements in queue == maxQueueSize)
			return TRUE
		else return FALSE
		
	Queue EnQueue(queue, item):
		if (IsFull(queue))
			queueFull
		else
			insert item at rear of queue and return
	
	Boolean IsEmpty(queue):
		if (queue is empty) return TRUE
		else return FALSE
		
	Element DeQueue(queue):
		if (IsEmpty(queue)) return
		else remove and return the item at front of the queue
*/


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


int main(int argc, char *argv[]) {
	Queue *q = CreateQueue();
	
	Element e;
	e.key = 1;
	EnQueue(q, e);
	Element e2 = DeQueue(q);
	printf("%d", e2.key);
}

Queue * CreateQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	q->capacity = 1;
	q->queue = (Element *)malloc(sizeof(Element) * q->capacity);
	return q;
}

int IsEmpty(Queue *q)
{
	return (q->front == q->rear);
}

int IsFull(Queue *q)
{
	return q->rear >= q->capacity - 1;
}

void EnQueue(Queue *q, Element element)
{
	if (IsFull(q)) 
	{
		printf("Queue overflow error");
		exit(-1);
	}
	
	q->queue[++(q->rear)] = element;
}

Element DeQueue(Queue *q)
{
	if (IsEmpty(q)) {
		printf("Queue underflow error");
		exit(-1);
	}
	return q->queue[ ++(q->front) ];
}
