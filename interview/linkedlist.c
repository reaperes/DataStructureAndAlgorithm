#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
} node_t;

typedef struct list {
	node_t *head;
} list_t;


void add_first(int key);
void print();


list_t list;

int main(int argc, char *argv[]) {
	add_first(1);	add_first(2);	add_first(3);	add_first(4);	add_first(5);
	print();
}

void print()
{
	node_t *node;
	
	node = list.head;
	
	if (node == NULL)
		printf("There is not a node.\n");
	else
	{
		while (node)
		{
			printf("%d ", node->key);
			node = node->next;
		}
		printf("\n");
	}
}

void add_first(int key)
{
	node_t *temp;
	node_t *node = (node_t *) malloc(sizeof(node_t));
	
	node->key = key;
	node->next = NULL;
	
	if (list.head == NULL)
		list.head = node;
	else
	{
		temp = list.head;
		list.head = node;
		node->next = temp;
	}
}