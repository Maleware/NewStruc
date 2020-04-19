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
	while(getchar() != '#')
		inputlist();
	return EXIT_SUCCESS;
}


int ex70(void)
{
	return linlist();
}
