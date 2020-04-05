#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
};


int cmp_structs(struct adres *str1, struct adres *str2)
{
	//First name equal
	if(strcmp(str1->fname, str2->fname) == 0 && 
	// Last name equal
	strcmp(str1->lname, str2->lname) == 0 &&
	// ZIP equal
	(str1->zip-str2->zip) == 0 &&
	// Place equal
	strcmp(str1->place, str2->place) == 0 &&
	// Year of Birth equal
	(str1->yob-str2->yob) == 0 )
		return 0; // Structures equal
	else
		return 1; // Strutures not equal
}

struct adres *input2(void)
{
	static struct adres *adresses;
	adresses = malloc(sizeof(struct adres));
	printf("First Name	:");
	fgets(adresses->fname, MAX, stdin);
	printf("Last Name	:");
	fgets(adresses->lname, MAX, stdin);
	printf("Zip Code	:");
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

void output5(struct adres *struct_ptr)
{
	printf("\n\nYour Informations are:\n");
	printf("First Name......:%s",struct_ptr->fname);
	printf("Last Name.......:%s",struct_ptr->lname);
	printf("Zip Code........:%ld\n",struct_ptr->zip);
	printf("Place...........:%s",struct_ptr->place);
	printf("Year of Birth...:%d\n",struct_ptr->yob);
}

void struct5(void)
{
	struct adres *adresses1, *adresses2;


	adresses1 = input2();
	adresses2 = input2();

	if (cmp_structs(adresses1, adresses2)==0)
	{
		printf("Adresses are equal, please try again\n");
	}
	else
	{
		output5(adresses1);
		output5(adresses2);
	}
}

int ex24(void)
{
	struct5();
	return 0;
}
