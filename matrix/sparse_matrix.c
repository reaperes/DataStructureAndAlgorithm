#include <stdio.h>

#define MAX_COL 101
#define MAX_TERMS 101

typedef struct term {
	int cid;		// column id
	int rid;		// row id
	int value;
} tTerm;

tTerm a[MAX_TERMS + 1];

int main(int argc, char *argv[]) {
	
}

void transpose(tTerm a[], tTerm b[])
{
	int n, aId, bId, colId;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	n = a[0].value;
	
	if (n > 0)
	{
		bId = 1;
		for (colId = 0; colId < a[0].columns; colId++)
		{
			for (aId = 1; aId <= n; aId++)
			{
				if (a[aId].col == colId)
				{
					b[bId].row = a[aId].col;
					b[bId].col = a[aId].row;
					b[bId].value = a[aId].value;
					++bId;
				}
			} // end of aId-loop
		} // end of colId-loop
	} // end of if
}

void fastTranspose(tTerm a[], tTerm b[])
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	
	if (numTerms > 0)
	{
		for (i=0; i<numCols; ++i)
			rowTerm[i] = 0;
		for (i=1; i<=numTerms; ++i)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i=1; i<=numCols; ++i)
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];
		for (i=1; i<=numTerms; ++i)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
