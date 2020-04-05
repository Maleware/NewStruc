#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30

static int x=0;

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
}adresses[100]; // Enables 100 Adresses

// Classical input function for Structures

void Input(int nr, struct adres new[])
{
	printf("First Name......:");
	fgets(new[nr].fname, MAX, stdin);
	printf("Last Name.......:");
	fgets(new[nr].lname, MAX, stdin);
	printf("Zip code........:");
	do
	{
		scanf("%5ld",&new[nr].zip);
	}while(getchar()!='\n');
	printf("Place...........:");
	fgets(new[nr].place,MAX,stdin);
	printf("Year of Birth...:");
	do
	{
		scanf("%4d",&new[nr].yob);
	}while(getchar()!='\n');
}

// Search a dedicatet entry

void search(struct adres search[], char letter, int nr)
{
	int i;

	for(i=0; i<=nr; i++)
	{
		if(search[i].lname[0]==letter)
		{
			printf("\n\n Found by letter"
			       ":\"%c\"\n\n", letter);
			printf("First name......:%s",search[i].fname);
			printf("Last name.......:%s",search[i].lname);
			printf("Zip code........:%ld\n",search[i].zip);
			printf("Place...........:%s",search[i].place);
			printf("Year of birth...:%d",search[i].yob);
			printf("\n\t Continue with <ENTER>\n");
			getchar();
		}
	}	
}

// Printout structures

void Output(struct adres all[], int nr)
{
	int i;

	for(i=0; i<nr; i++)
	{
		printf("First name......:%s",all[i].fname);
		printf("Last name.......:%s",all[i].lname);
		printf("Zip code........:%ld\n",all[i].zip);
		printf("Place...........:%s",all[i].place);
		printf("Year of Birth...:%d\n",all[i].yob);

		if((!(i%2)) && i!=0)
		{
			printf("\n\t Continue with <ENTER>\n\n");
			getchar();
		}
	}
}

// sorting entries alphabetical

void sort(struct adres sort[], int nr)
{
	int i,j;
	struct adres *temp;

	temp = malloc(sizeof(struct adres *));
	if(NULL == temp)
	{
		printf("no memory available...\n");
		return;
	}
	for(i=0; i < nr; i++)
	{
		for(j=i+1;j<nr;j++)
		{
			if(strcmp(sort[i].lname, sort[j].lname)>0)
			{
				*temp=sort[j];
				sort[j]=sort[i];
				sort[i]=*temp;
			}
		}
	}
	printf(".....Sorted!!\n\n");
}

void struct_arr2(void)
{
	int sel;
	char c;

	do
	{
		printf("-1- Insert new adress\n");
		printf("-2- Print dedicated adress\n");
		printf("-3- Print all adresses\n");
		printf("-4- Sort adresses\n");
		printf("-5- End Programmn\n");
		printf("\nYour Choice	: ");
		scanf("%d",&sel);
		fflush(stdin);
		getchar();

		switch(sel)
		{
			case 1 :
				Input(x++, adresses);
				break;
			case 2 :
				printf("First letter of last name : ");
				do
				{
					scanf("%c",&c);
				}while(getchar()!='\n');
				search(adresses,c,x);
				break;
			case 3 :
				Output(adresses,x);
				break;
			case 4 :
				sort(adresses,x);
				break;
			case 5 :
				printf("End....\n");
				break;
			default:
				printf("Wrong input\n");

		}

	}while(sel<5);
}

int ex26(void)
{
	struct_arr2();
	return 0;
}
