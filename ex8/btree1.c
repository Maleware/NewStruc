#include <stdio.h>
#include <stdlib.h>

struct knot
{
	int value;
	struct knot *left;
	struct knot *right;
};

typedef struct knot KNOT;

int numb;

KNOT *fitin(KNOT *pointer)
{
	if(pointer == NULL) // First entrie
	{
		pointer=malloc(sizeof(KNOT));
		if (pointer == NULL)
		{	
			fprintf(stderr, "Unable to reserve memorie\n");
			exit (EXIT_FAILURE);
		}
		pointer->value=numb;
		pointer->left = pointer->right=NULL;
	}
	else if(pointer->value >=numb)
		pointer->left=fitin(pointer->left);
	else if(pointer->value <=numb)
		pointer->right=fitin(pointer->right);
	return (pointer);
}

int btree1(void)
{
	KNOT *root=NULL;

	do
	{
		fprintf(stdout, "\nInsert Number...>");
		do
		{
			scanf("%d", &numb);
		}while(getchar() != '\n');
		root=fitin(root);
	}while(numb != 0);
	return EXIT_SUCCESS;
}

int ex89(void)
{
	return btree1();
}
