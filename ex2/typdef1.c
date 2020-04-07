#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30

static int x;

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
}adresses[100];

typedef struct adres ADRESSES;

void inputna(int nr, ADRESSES *new)
{
	printf("First name......:");
	fgets(new[nr].fname, MAX, stdin);
	printf("Last name.......:");
	fgets(new[nr].lname, MAX, stdin);
	printf("Zip Code........:");
	do
	{
		scanf("%5ld", &new[nr].zip);
	}while(getchar()!= '\n');
	printf("Place...........:");
	fgets(new[nr].place, MAX, stdin);
	printf("Year of birth...:");
	do
	{
		scanf("%4d",&new[nr].yob);
	}while(getchar()!='\n');
}

void searchlet(ADRESSES *search, char letter, int nr)
{
	int i;
	for (i=0; i <= nr; i++)
	{
		if(search[i].lname[0] == letter)
		{
			printf("\n\n Found by letter : \"%c\"\n\n",letter);
			printf("First name......: %s", search[i].fname);
			printf("Last name.......: %s", search[i].lname);
			printf("Zip Code........: %5ld", search[i].zip);
			printf("Place...........: %s", search [i].place);
			printf("Year of Birth...: %4d", search[i].yob);
			printf("\n\t Continue with <ENTER>\n");
			getchar();
		}
	}
}

void outputad(ADRESSES *all, int nr)
{
	int i;

	for(i=0; i<nr; i++)
	{
		printf("First name......: %s", all[i].fname);
		printf("Last name.......: %s", all[i].lname);
		printf("Zip Code........: %5ld", all[i].zip);
		printf("Place...........: %s", all[i].place);
		printf("Year of Birth...: %4d", all[i].yob);

		if( (!(i%2)) && i!=0)
		{
			fflush(stdin);
			printf("\n\t Continue with <ENTER>\n");
			getchar();
		}
	}
}

void sortad(ADRESSES *sort, int nr)
{
	ADRESSES *temp;
	int i,j;

	temp = malloc(sizeof(ADRESSES *));
	if(NULL == temp)
	{
		printf("No memory available... \n");
		return;
	}
	for(i=0; i<nr; i++)
	{
	   	for(j=i+1; j<nr; j++)
	   	{

	   
			if(strcmp(sort[i].lname, sort[j].lname)>0)
			{
				*temp=sort[j];
				sort[j]=sort[i];
				sort[i]=*temp;
	  		}
	    	}		
	}
	printf("Sorted.....\n");
}

void typedef1(void)
{
	int select;
	char c;

	do
	{
		printf("-1- Insert new Adress\n");
		printf("-2- Print dedicated adress\n");
		printf("-3- Print all adresses\n");
		printf("-4- Sort adresses\n");
		printf("-5- End programm\n");
		printf("\n Your choice:	");
		scanf("%d",&select);
		fflush(stdin);
		getchar();

		switch(select)
		{
			case 1: inputna(x++, adresses);
				break;
			case 2: printf("First letter of last name:	");
				do
				{
					scanf("%c",&c);
				}while(getchar()!='\n');
				searchlet(adresses,c,x);
				break;
			case 3: outputad(adresses,x);
				break;
			case 4: sortad(adresses,x);
				break;
			default: break;
		}
	}while(select <5);
}

int ex210(void)
{
	typedef1();
	return EXIT_SUCCESS;
}
