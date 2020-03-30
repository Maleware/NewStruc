#include "../output.h"
#include "../input.h"
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

void D_dyn_array(void)
{	
	int i, j, row, column;
	// Matrix is pointer to int-pointer
	int** matrix;

	printout("How many columns?");
	scanf("%d", &column);
	fflush(stdin);
	printout("How many rows?");
	scanf("%d", &row);
	fflush(stdin);

	// allocate space for int-pointer (column)
	matrix = malloc(row*sizeof(int*));
	if (NULL==matrix)
	{
		printout("No virtual RAM available.");
	}
	// reserve now space for each column of i-row
	for(i=0; i<row; i++)
	{
		matrix[i]=malloc(column&sizeof(int));
		if (NULL==matrix)
		{
		printout("No virtual RAM available.");
		}	
	}
	// initial with abitrary values
	for (i=0; i<row; i++)
		for(j=0;j<column;j++)
			matrix[i][j]=i+j; // matrix[row][column]

	// print value of matrix
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			printf("%d",matrix[i][j]);
		printf("\n");
	}

	// free allocated space
	for(i=0;i<row;i++)
		free(matrix[i]);
}

int ex12(void)
{
	D_dyn_array();
	return 0;
}
