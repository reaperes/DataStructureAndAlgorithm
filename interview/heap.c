#include <stdio.h>
#include <stdlib.h>

#define LEN (1<<6)
#define PARENT(x) x>>1
#define LCHILD(x) x<<1
#define RCHILD(x) (x<<1)+1


typedef int HData;
typedef int Priority;
typedef struct {
	Priority prio;
	HData data;
} HElem;

int numData;
HElem heapArr[LEN];

int isEmpty() {return numData==0;}
void init() {numData=0;}
void HInsertElement(HElem el);
void HInsertData(Priority prio, HData data);
HData HDelete();
void print();

int main(int argc, char *argv[]) {
	heapArr[1].prio = 10;
	heapArr[2].prio = 6;
	heapArr[3].prio = 8;
	heapArr[4].prio = 4;
	numData = 4;
	
	print();
	
	HElem e1;
	e1.prio = 11;
	
	HInsertElement(e1);
	HInsertElement(e1);
	print();

	HDelete();
	print();

	HDelete();
	print();

	HDelete();
	print();

	HDelete();
	print();
}

void print() {
	int i, lineCount;
	
	lineCount = 1;
	for (i=1; i<=numData; ++i)
	{
		printf("%d ", heapArr[i].prio);
		if (i == lineCount)
		{
			printf("\n");
			lineCount = lineCount * 2 + lineCount;
		}
	}
	printf("\n\n");
}

void HInsertElement(HElem el) {
	int idx = ++numData;
	
	while (idx > 1 && heapArr[PARENT(idx)].prio < el.prio) {
		heapArr[idx] = heapArr[PARENT(idx)];
		idx = PARENT(idx);
	}
	heapArr[idx] = el;
}

HData HDelete() {
	int ret = heapArr[1].prio;
	HElem temp = heapArr[numData--];
	
	int parent = 1;
	int child = 2;
	while (child <= numData) {
		if ( (child < numData) && heapArr[child].prio < heapArr[child+1].prio)
			++child;
		if (temp.prio >= heapArr[child].prio)
			break;
		heapArr[parent] = heapArr[child];
		parent = child;
		child <<= 1;
	}
	heapArr[parent] = temp;
	return ret;
}