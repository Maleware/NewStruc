#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 30

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
};

// Output of sentence

void output3(struct adres *struct_ptr)
{
	printf("\n\nYour informations are:\n\n");
	printf("First Name......:%s",struct_ptr->fname);
	printf("Last Name.......:%s",struct_ptr->lname);
	printf("Zip Code........:%ld\n",struct_ptr->zip);
	printf("Place...........:%s",struct_ptr->place);
	printf("Year of Birth...:%d\n",struct_ptr->yob);
}

struct adres *input1(void)
{
	static struct adres *adresses;
	adresses = malloc(sizeof(struct adres));
	printf("First Name	:");
	fgets(adresses->fname, MAX, stdin);
	printf("Last Name	:");
	fgets(adresses->lname, MAX, stdin);
	printf("ZIP Code	:");
	do
	{
		scanf("%5ld",&adresses->zip);
	}while(getchar()!='\n');
	printf("Place		:");
	fgets(adresses->place, MAX, stdin);
	printf("Year of Birth	:");
	do
	{
		scanf("%4d",&adresses->yob);
	}while(getchar()!='\n');
	return adresses;
}

void struct4(void)
{
	struct adres *adresses1, *adresses2;

	adresses1 = input1();
	adresses2 = input1();

	output3(adresses1);
	output3(adresses2);
}

int ex23(void)
{
	struct4();
	return 0;
}
