#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct reservation
{
	char lname[MAX];
	char fname[MAX];
	int rnumber;
	struct reservation *previous;
};

struct reservation *dummy;
static int number=1;

int queue_init(void)
{
	if( (dummy=malloc(sizeof(struct reservation))) != NULL)
	{
		strcpy(dummy->lname,"dummy");
		strcpy(dummy->fname,"dummy");
		dummy->rnumber=0;
		dummy->previous=NULL;
		return 1;
	}
	else
	{
		fprintf(stderr, "Unable to reserve memory\n");
		return 0;
	}
}

// New element in queue
int put(struct reservation *new)
{
	struct reservation *pointer;

	// First Element of Queue?
	if(dummy->previous==NULL) // First element
	{
		dummy->previous=new;
		new->previous= NULL;
		return 1;
	}
	// Not first element
	else
	{
		pointer=dummy;
		// Search for end of queue
		while(pointer->previous != NULL)
			pointer=pointer->previous;
		pointer->previous=new;
		new->previous=NULL;
		return 1;
	}
}

//We need the first inserted element in the list, therefore dummy->previous
void get(void)
{
	struct reservation *pointer;

	//is something queued?
	if(dummy->previous != NULL) // Yes...
	{
		pointer=dummy->previous;
		dummy->previous=pointer->previous;
		free(pointer);
	}
	else
		fprintf(stderr, "nobody in queue..\n");
}

void inputq(void)
{
	struct reservation *new;
	char ln[MAX], fn[MAX];

	if( (new=(struct reservation *) malloc(sizeof(struct reservation))) != NULL)
	{
		fprintf(stdout, "\nLast Name.......>");
	        fgets(ln, MAX, stdin);
		strcpy(new->lname, strtok(ln, "\n"));
		fprintf(stdout, "\nFirst name......>");
		fgets(fn, MAX, stdin);
		strcpy(new->fname, strtok(fn, "\n"));
		fprintf(stdout, "\nNumber...: %d",new->rnumber=number++);
		new->previous=NULL;
		put(new);
	}
}

void outputq(void)
{
	if(dummy->previous !=NULL)
	{
		fprintf(stdout, "\n%s, %s Number.: %d \n\n",
				dummy->previous->lname,
				dummy->previous->fname,
				dummy->previous->rnumber);
		get();	
	}
	else
		fprintf(stderr, "\nNobody left....\n");
}

int queue(void)
{
	int select;

	queue_init();

	do
	{
		fprintf(stdout, "-1- Insert reservation\n");
		fprintf(stdout, "-2- Next Person\n");
		fprintf(stdout, "-3- End...\n");
		fprintf(stdout, "Your choice...>");
		do
		{
			scanf("%d",&select);
		}while(getchar() != '\n');
		switch(select)
		{
			case 1:
				inputq();
				break;
			case 2:
				outputq();
				break;
			case 3:
				if(dummy->previous != NULL)
				{
					fprintf(stderr, "Still persons available....\n");
					select = 4;
				}
				break;
			case 4: 
				break;
			default: fprintf(stderr, "Wrong input...\n");
		}
	}while(select != 3);
	fprintf(stdout, "See you tomorrow master...\n\n");
	return EXIT_SUCCESS;
}

int ex72(void)
{
	return queue();
}
