#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int key;
	struct _Node *left;
	struct _Node *right;
} Node;

typedef struct {
	Node **queue;
	int front;
	int rear;
	int capacity;
} Queue;

Queue * CreateQueue();
void DestroyQueue(Queue *q);
int IsEmpty(Queue *q);
int IsFull(Queue *q);
void EnQueue(Queue *q, Node *element);
Node * DeQueue(Queue *q);
void ExtendQueue(Queue *q);
void copy(Node **src, int srcStartIdx, int srcEndIdx, Node **dst, int dstStartIdx);
Node * CreateNode(int key);
void DestroyNode(Node *node);


int main(int argc, char *argv[])
{
	Queue *q = CreateQueue();
	
	Node *n = CreateNode(1);
	EnQueue(q, n);

	n = CreateNode(4);
	n->key = 2;
	EnQueue(q, n);
	EnQueue(q, n);
	EnQueue(q, n);

	Node * e2 = DeQueue(q);
	printf("%d\n", e2->key);
	
	DestroyQueue(q);
}

Queue * CreateQueue()
{
	Queue *q = (Queue *) malloc( sizeof(Queue) );
	q->front = 0;
	q->rear = 0;
	q->capacity = 2;
	q->queue = (Node **) malloc( sizeof(Node *) * q->capacity );
	return q;
}

void DestroyQueue(Queue *q)
{
	free(q->queue);
	free(q);
}

int IsEmpty(Queue *q)
{
	return (q->front == q->rear);
}

int IsFull(Queue *q)
{
	return (q->rear + 1) % q->capacity == q->front;
}

void EnQueue(Queue *q, Node *element)
{
	if (IsFull(q)) 
		ExtendQueue(q);
	q->rear = (q->rear + 1) % q->capacity;
	q->queue[ q->rear ] = element;
}

Node * DeQueue(Queue *q)
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
	Node **newQueue;
	newQueue = (Node **)malloc( sizeof(Node *) * 2 * q->capacity );
	
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

void copy(Node **src, int srcStartIdx, int srcEndIdx, Node **dst, int dstStartIdx)
{
	int idx = 0;
	for (int i=srcStartIdx; i<=srcEndIdx; ++i)
		dst[ dstStartIdx + idx++ ] = src[i];
}

Node * CreateNode(int key)
{
	Node *node = (Node *) malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void DestroyNode(Node *node)
{
	if (node == NULL)
		return;
	if (node->left)
		DestroyNode(node->left);
	if (node->right)
		DestroyNode(node->right);
	free(node);
}
