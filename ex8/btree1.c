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
	if(pointer == NULL) // First entrie, or not end of tree
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

/*
void show_tree(KNOT *pointer)
{
	if(pointer != NULL)
	{
		fprintf(stdout, "\n%d ->", pointer->value);
		show_tree(pointer->left);
		show_tree(pointer->right);				
	}
}

void delete_knot(KNOT **pointer)
{
	KNOT *temp;
	int tempvalue;

	if(global_root == *pointer)
	{
		fprintf(stderr, "Unable to delete root...\n");
		return;
	}
	if( (*pointer) != NULL) // Leaf
	{
		if( (*pointer)->left == NULL && (*pointer)->right==NULL)
		{
			free(*pointer);
			*pointer = NULL;
		}
		else if( (*pointer)->left==NULL) // Only right hand side can follow
		{
			temp = *pointer;
			*pointer = (*pointer)->right;
			free(temp);
		}
		else if( (*pointer)->right==NULL) // Only left hand side can follow
		{
			temp=*pointer;
			*pointer = (*pointer)->left;
			free(temp);
		}
		else // Looking for second follower replacement element
		{
			search_replace(&tempvalue, &( (*pointer)->right));
			(*pointer)->value=tempvalue;
		}
	}
}

void searchknot(KNOT **pointer, int search)
{
	if( (*pointer) == NULL)
		fprintf(stdout, "Empty tree...\n");
	else if( (*pointer)->value == search) //Found knot
		delete_knot(pointer);
	else if( (*pointer)->value >= search)
		searchknot(&((*pointer)->left), search);
	else
		searchknot(&((*pointer)->right), search);
}

*/ 

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
