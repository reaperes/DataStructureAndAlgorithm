#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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


#define MAX_HEIGHT	5

int maxNodeByHeight[ MAX_HEIGHT ] = {0};

typedef struct {
	Node *root;
	int numOfNodes;
} Tree;

Node * CreateNode(int key);
void DestroyNode(Node *node);
void PrintNode(Node *node);
void PrintSpace(int num);
void PrintKey(int key);
Tree * CreateTree();
void DestroyTree(Tree *tree);
void PrintTree(Tree *tree);
void Push(Tree *tree, int key);
void push(Tree *tree, int key, Node **curNode);
int FindHeight(Tree *tree);
int findMaxHeight(Tree *tree, Node *curNode);
void BsfInit(Tree *tree);
int BsfNext();


Queue *queue;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	for (int i=0; i<MAX_HEIGHT; ++i)
		maxNodeByHeight[i] = pow(2, i) - 1;
	queue = CreateQueue();

//	Tree *tree;
//	tree = CreateTree();
//
//	for (int i=0; i<2; ++i)
//		Push(tree, i+1);
//	PrintTree(tree);
//
//	DestroyTree(tree);
	
	Queue *q = CreateNode(4);
	Queue *w = CreateNode(2);
	
	Push(tree, q);
	Push(tree, w);
	
	DestroyQueue(queue);
}

void PrintTree(Tree *tree)
{
	if (tree->root == NULL)
		printf("%s\n", "Tree is empty.");
	else
	{
		BsfInit(tree);
		int maxHeight = FindHeight(tree);

		for (int height=1; height<=maxHeight; ++height)
		{
			// print first spaces
			PrintSpace( maxNodeByHeight[ maxHeight - height ] );
			// print first node
			int key = BsfNext();
			if (key)
				PrintKey(key);
			else
				PrintSpace(1);
				
			// print other node			
			for (int node = 1, maxNode = pow(2, height-1); node < maxNode; ++node)
			{
				PrintSpace( maxNodeByHeight[ maxHeight - height + 1 ] );
				int key = BsfNext();
				if (key)
					PrintKey(key);
				else
					PrintSpace(1);
			}
			printf("\n");
		}
	}
}

void PrintSpace(int num)
{
	for (int i=0; i<num; ++i)
		printf("   ");
}

void PrintKey(int key)
{
	printf("%3d", key);
}

void PrintNode(Node *node)
{
	printf("%3d", node->key);
}

void BsfInit(Tree *tree)
{
	if (tree->root == NULL)
		exit(1);
	EnQueue(queue, tree->root);
}

// Customized BSF
int BsfNext()
{
	int ret;
	Node *node = DeQueue(queue);
	if (node != NULL)
	{
		ret = node->key;
		EnQueue(queue, node->left);
		EnQueue(queue, node->right);
	}
	else
	{
		ret = 0;
		EnQueue(queue, NULL);
		EnQueue(queue, NULL);
	}
	return ret;
}

int FindHeight(Tree *tree)
{
	return findMaxHeight(tree, tree->root);
}

int findMaxHeight(Tree *tree, Node *curNode)
{
	int left, right;
	
	if (curNode == NULL)
		return 0;
	
	left = findMaxHeight(tree, curNode->left);
	right = findMaxHeight(tree, curNode->right);
	
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

void Push(Tree *tree, int key)
{
	push( tree, key, &(tree->root) );
	++(tree->numOfNodes);
}

void push(Tree *tree, int key, Node **curNode)
{
	if (*curNode == NULL)
		*curNode = CreateNode(key);
	else
	{
		if (key < (*curNode) -> key )
			push( tree, key, &( (*curNode) -> left ) );
		else if (key > (*curNode) -> key )
			push( tree, key, &( (*curNode) -> right ) );
		else
			printf("Tree push error. Key is duplicated.");
	}
}

Tree * CreateTree()
{
	Tree *tree = (Tree *) malloc(sizeof(Tree));
	tree->numOfNodes = 0;
	return tree;
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

void DestroyTree(Tree *tree)
{
	DestroyNode(tree->root);
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
