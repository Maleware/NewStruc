#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

struct binary_knot
{
	char place[MAX];
	unsigned int zip;
	struct binary_knot *left;
	struct binary_knot *right;
};

struct binary_tree
{
	struct binary_knot *root;
	unsigned int counter;
};

struct binary_tree *inittree(void)
{
	struct binary_tree *tree=malloc(sizeof *tree);
	if(tree == NULL)
	{
		fprintf(stderr, "No memory available...\n");
		return NULL;
	}
	else // Init
	{
		tree->root = NULL;
		tree->counter = 0;
		return tree;
	}
}

int insertbk(struct binary_tree *tree, unsigned int p, char *o)
{
	struct binary_knot *knot, **new;

	new = (struct binary_knot **) &tree->root;
	knot= (struct binary_knot * )  tree->root;

	for(;;) // Infinite loop
	{
		if(knot == NULL) // Did we find a free space?
		{
			knot = *new = malloc(sizeof *knot);
			if (knot != NULL) // insert new data
			{
				knot->zip = p;
				strcpy(knot->place, o);
				knot->left = knot->right = NULL; // Leaf
				tree->counter++;
				return 1;
			}
		}
		else if( p > knot->zip) // New plz is taller
		{ // Move on at right hand side
			new = &knot->right;
			knot = knot->right;
		}
		else // New plz is smaller
		{ // Move on at left hand side
			new = &knot->left;
			knot = knot->left;
		}
	}
}

void binary_search_zip(const struct binary_tree *tree, unsigned int p)
{
	const struct binary_knot *knot;

	// first back to root
	knot = (struct binary_knot *) tree->root;
	for(;;)
	{
		if(knot == NULL)
		{
			fprintf(stderr, "No result available...\n");
			return;
		}
		if(p == knot->zip) //found
		{
			fprintf(stdout, "City to zipcode %d is %s\n\n", p, knot->place);
			return;
		}
		else if(p > knot->zip) // Searched element taller
			knot=knot->right; // move on at right hand side
		else
			knot=knot->left; // left hand side otherwise
	}
}

int binary_delete(struct binary_tree *tree, unsigned int p)
{
	// pointer_z is the element we want to delete
	struct binary_knot **pointer_q, *pointer_z,
			   *pointer_y, *pointer_x;

	pointer_q = (struct binary_knot **) &tree->root;
	pointer_z = (struct binary_knot  *)  tree->root;

	for(;;)
	{
		if(pointer_z == NULL)
			return 0;
		else if( p == pointer_z->zip) //found element we want to delte
			break;
		else if( p > pointer_z->zip)
		{
			pointer_q = &pointer_z->right;
			pointer_z = pointer_z->left;
		}
	}// only reachable through break --> found the element we were looking for

	// Now we study pointer_z
	if(pointer_z->right == NULL) // pointer_z has no right follow up --> exchange with left follow up
		*pointer_q = pointer_z->left;
	else // pointer_z has no left follow up but a left one
	{
		pointer_y = pointer_z->right;
		if(pointer_y->left == NULL) // pointer_z->right has no left follow up
		{
			pointer_y->left = pointer_z->left;
			*pointer_q = pointer_y;
		}
		else
		{// has left follow up
			pointer_x = pointer_y->left;
			while(pointer_x->left != NULL)
			{
				pointer_y = pointer_x;
				pointer_x = pointer_y->left;
			}
		// collected all ends and link them together
		pointer_y->left = pointer_x->right;
		pointer_x->left = pointer_z->left;
		pointer_x->right= pointer_z->right;
		*pointer_q = pointer_x;
		}
	}
	// At least we can free pointer_z
	tree->counter--;
	free(pointer_z);
	return 1;
}

int btree3(void)
{
	struct binary_tree *re;
	char o[MAX];
	unsigned int p;
	int select, r;

	re = inittree();
	
	if(re == NULL)
	{
		fprintf(stderr, "Unable to create tree...\n");
		return EXIT_FAILURE;
	}
	else
		fprintf(stdout, "Sucessfully created binary tree...\n");

	do
	{
		fprintf(stdout, "\n\t-1- Add new ZIP-Code"
				"\n\t-2- Search for ZIP-Code"
				"\n\t-3- Delete ZIP-Code"
				"\n\t-4- End \n\n"
				"\n\t Your Choice...>");
		do
		{
			scanf("%d", &select);
		}while(getchar() != '\n');


		if(select == 1)
		{
			fprintf(stdout, "Please insert new ZIP-Code...>");
			do
			{
				scanf("%5u", &p);
			}while(getchar() != '\n');

			fprintf(stdout, "Corresponding City...>");
			fgets(o, MAX, stdin);
			r=insertbk(re, p, strtok(o, "\n"));
			if(r == 0)
				return EXIT_FAILURE;
		}
		else if(select == 2)
		{
			fprintf(stdout, "Insert Zipcode you are looking for...>");
			do
			{
				scanf("%5u", &p);
			}while(getchar() != '\n');
			binary_search_zip(re, p);
		}
		else if(select == 3)
		{
			fprintf(stdout, "Which ZIP-Code to delete...>");
			do
			{
				scanf("%5u", &p);
			}while(getchar() != '\n');
			binary_delete(re, p);
		}
	}while(select != 4);
	return EXIT_SUCCESS;
}

int ex810(void)
{
	return btree3();
}
