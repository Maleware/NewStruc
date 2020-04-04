#include "../input.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
}adresses;

// Function for outputting the structures values

void output1(struct adres *struct_ptr)
{
	printf("\n\nYour informations are:\n\n");
	printf("First Name.......:%s",(*struct_ptr).fname);
	printf("Last Name........:%s",(*struct_ptr).lname);
	printf("ZIP-Code.........:%ld\n",(*struct_ptr).zip);
	printf("Place............:%s",(*struct_ptr).place);
	printf("Year of Birth....:%d\n",(*struct_ptr).yob);
}

void struct3(void)
{
	printf("First Name	:");
	fgets(adresses.fname, MAX, stdin);
	printf("Last Name	:");
	fgets(adresses.lname, MAX, stdin);
	printf("ZIP Code 	:");
	do
	{
		scanf("%5ld",&adresses.zip);
	}while(getchar()!='\n');
	printf("Place		:");
	fgets(adresses.place, MAX, stdin);
	printf("Year of Birth	:");
	do
	{
		scanf("%4d",&adresses.yob);
	}while(getchar()!='\n');

	output1(&adresses);
}

int ex22(void)
{
	struct3();
	return 0;
}
