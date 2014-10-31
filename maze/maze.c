#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_ROW 12
#define MAX_MAZE_COL 12

typedef enum {
	None=0, N, NE, E, SE, S, SW, W, NW
} Direction;

int maze[MAX_MAZE_ROW][MAX_MAZE_COL] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 
	1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1,
	1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1,
	1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
	1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
	1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
	1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
	1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

typedef struct {
	short int row;
	short int col;
} Position;

Position move[] = {
	{.row =  0, .col =  0},
	{.row = -1, .col =  0},
	{.row = -1, .col =  1},
	{.row =  0, .col =  1},
	{.row =  1, .col =  1},
	{.row =  1, .col =  0},
	{.row =  1, .col = -1},
	{.row =  0, .col = -1},
	{.row = -1, .col = -1}
};

typedef struct {
	Position *stack;
	int top;
	int capacity;
} Stack;

Stack * CreateStack()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
	s->capacity = 1;
	s->stack = (Position *)malloc(sizeof(Position) * s->capacity);
	return s;
}

int IsEmpty(Stack *s)
{
	return s->top < 0;
}

int IsFull(Stack *s)
{
	return s->top >= s->capacity - 1;
}

void ExtendStack(Stack *s)
{
	s->stack = realloc(s->stack, 2 * s->capacity * sizeof(Position));
	s->capacity *= 2;
}

void Push(Stack *s, Position element)
{
	if (IsFull(s))
		ExtendStack(s);
	s->stack[++(s->top)] = element;
}

Position Pop(Stack *s)
{
	if (IsEmpty(s))
	{
		printf("Underflow error occured.");
		exit(-1);
	}
	return s->stack[ s->top-- ];
}

void Print(Stack *s)
{
	if (IsEmpty(s))
		printf("Empty stack\n");
	
	printf("===================================\n");
	for (int i=s->top; i>=0; --i)
		printf("%d %d\n", (s->stack+i)->row, (s->stack+i)->col);
}



Direction findDirection(Position curPos);
int isValid(int row, int col);
void movePosition(Position *curPos, Direction direction);


int main(int argc, char *argv[])
{
	Position curPos;
	curPos.row = 1;
	curPos.col = 1;
	
	Stack *trace = CreateStack();
	Push(trace, curPos);

	for (int i=0; i<100; ++i)
	{	
		printf("%d %d\n", curPos.row, curPos.col);
		Direction direction = findDirection(curPos);
		if (direction != None)
		{
			maze[curPos.row][curPos.col] = 2;
			movePosition(&curPos, direction);
			if (curPos.row == 10 && curPos.col == 10)
			{
				Push(trace, curPos);
				Print(trace);
				free(trace->stack);
				free(trace);
				exit(0);
			}
			Push(trace, curPos);
		}
		else
		{
			maze[curPos.row][curPos.col] = 2;
			printf("%d %d = %d\n", curPos.row, curPos.col, maze[curPos.row][curPos.col]);
			curPos = Pop(trace);
		}
	}
}

// Find direction which character can move
// If None, it returns None
Direction findDirection(Position curPos)
{
	int nextRow, nextCol;

	for (int i=N; i<=NW; ++i)
	{
		nextRow = curPos.row + move[i].row;
		nextCol = curPos.col + move[i].col;
		if ( isValid(nextRow, nextCol) )
			return i;
	}
	return None;
}

int isValid(int row, int col)
{
	return row >= 0 
		&& col >= 0
		&& row < MAX_MAZE_ROW
		&& col < MAX_MAZE_COL
		&& *(*(maze + row) + col) == 0;
}

void movePosition(Position *curPos, Direction direction)
{
	curPos->row += move[direction].row;
	curPos->col += move[direction].col;
}