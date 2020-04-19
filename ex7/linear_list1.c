#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

struct date
{
	int day;
	int month;
	int year;
};

struct hired
{
	char lname[MAX];
	char fname[MAX];
	struct date age;
	struct date hire;
	long wage;
	struct hired *next;
};

struct hired *next=NULL;
struct hired *start=NULL;

/* We put some date behind or type in some new:
 * n=lname, f=fname, ad=age.day, am=age.month, ay=age.year,
 * hird=hire day, hirm=hire month, hiry=hire year, w=wage */

void connect(char *n, char *f, int ad, int am, int ay, int hird, 
		int hirm, int hiry, long w)
{
	// Pointer to access single elements of the structure
	struct hired *pointer;
	/* we ask first, if there is already an element in the list.
	 * if *start=NULL no elements are existing and *start points to
	 * the adress of our first element and is the starting element
	 * of the list */
	if(start==NULL)
	{
		if((start=malloc(sizeof(struct hired)))==NULL)
		{
			fprintf(stderr, "No memory available for start\n");
			exit (EXIT_FAILURE);
		}
		strcpy(start->lname, n);
		strcpy(start->fname, f);
		start->age.day = ad;
		start->age.month = am;
		start->age.year = ay;
		start->hire.day = hird;
		start->hire.month = hirm;
		start->hire.year = hiry;
		start->wage = w;
		/* Now we have the start of our list. From now on
		 * the pointer start points to the next element in
		 * front of it. Since this is the first element the 
		 * pointer start points to pointer next. next points
		 * at the end always to NULL */
		start->next=NULL;
	}
	/* It seems like there is already an Element existing in our list,
	 * since pointer start != NULL. Now we search for as long for the next
	 * Element until the *next pointer points to NULL. Then we found the
	 * End of our list and we can add annother file. */
	else
	{
		pointer=start; // Point to first element
		while(pointer->next !=NULL)
			pointer=pointer->next;
		// We reserve some Memory for the last Element and add it to
		// the list
		if( (pointer->next=malloc(sizeof(struct hired))) == NULL  )
		{
			fprintf(stderr, "No memory available for last Element");
			exit (EXIT_FAILURE);
		}
		pointer=pointer->next; // pointer to new memory space
		strcpy(start->lname, n);
		strcpy(start->fname, f);
		pointer->age.day = ad;
		pointer->age.month = am;
		pointer->age.year = ay;
		pointer->hire.day = hird;
		pointer->hire.month = hirm;
		pointer->hire.year = hiry;
		pointer->wage = w;
		pointer->next=NULL;
	}
}

void deletelist(char *wen)
{
	struct hired *pointer, *pointer1;

	// is there an Element?
	if(start != NULL)
	{
		// Is the first Element the one we are looking for?
		if(strcmp(start->lname, wen) == 0)
		{
			pointer=start->next;
			free(start);
			start=pointer;
		}
		else
		{
			/* if it's not the first element in the list,
			 * we have to search in the chain if the 
			 * element is available */
			pointer=start;
			while(pointer->next != NULL)
			{
				pointer1=pointer->next;
				// Is Adress of pointer1 the searched name?
				if( strcmp(pointer1->lname, wen) == 0)
				{
					// if yes, then...
					pointer->next=pointer1->next;
					free(pointer1);
					break;
				}
				pointer=pointer1;
			} // End while
		}	  // End else
	} 		  // End if(start != NULL)
	else
		fprintf(stderr, "Data not available. Wrong name?");
}

void outputlist(void)
{
	struct hired *pointer = start;

	printf("||==================================================="
			"==============\n");
	fprintf(stdout, "|%10cName%10c |Date of birth|Hired|Wage|\n",' ',' ');
	printf("||==================================================="
			"==============\n");

	while(pointer != NULL)
	{
		fprintf(stdout, "|%12s,%-12s| %02d.%02d.%04d|"
				"%02d.%02d.%04d|%06ld|\n",
				pointer->lname,pointer->fname,pointer->age.day,
				pointer->age.month, pointer->age.year,
				pointer->hire.day, pointer->hire.month,
				pointer->hire.year, pointer->wage);
		pointer=pointer->next;
	}
}

void inputlist(void)
{
	char lnam[MAX], fnam[MAX];
	int aday, amonth, ayear, hday, hmont, hyear;
	long wag;
	fprintf(stdout, "Last name...........:");
	fgets(lnam, MAX, stdin);
	fprintf(stdout, "First name..........:");
	fgets(fnam, MAX, stdin);
	fprintf(stdout, "Age.....(dd.mm.yyyy):");
	do
	{
		scanf("%2d.%2d.%4d",&aday,&amonth,&ayear);
	}while(getchar()!='\n');
	fprintf(stdout, "Hired on.(dd.mm.yyyy):");
	do
	{
		scanf("%2d.%2d.%4d",&hday, &hmont, &hyear);
	}while(getchar()!='\n');
	fprintf(stdout, "Monthly wage.........:");
	do
	{
		scanf("%ld",&wag);
	}while(getchar()!='\n');
	// Add insert data
	connect(lnam, fnam, aday, amonth, ayear, hday, hmont, hyear, wag);
}

int linlist(void)
{
	int select;
	char dname[MAX];
	while(1)
	{
		fprintf(stdout, "\n1 : Input\n");
		fprintf(stdout, "2: Output\n");
		fprintf(stdout, "3: Delete name\n");
		fprintf(stdout, "0: End\n");
		do
		{
			scanf("%d",&select);
		}while(getchar() !='\n');
		switch(select)
		{
			case 1: inputlist();
				break;
			case 2: outputlist();
				break;
			case 3: fprintf(stdout, "Input Name to delete: ");
				fgets(dname, MAX, stdin);
				deletelist(strtok(dname, "\n"));
				break;
			case 0: exit(EXIT_SUCCESS);
			default: fprintf(stderr, "Wrong input");
	
		}
	}
	return EXIT_SUCCESS;
}


int ex70(void)
{
	return linlist();
}
