#include "../input.h"
#include "../output.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct adres
{
	char fname[MAX];
	char sname[MAX];
	long zip;
	char place[MAX];
	int yob;
}adress;

//outputfunction

void output(struct adres x)
{
	printf("\n\n Your informations: \n");
	printf("First name.....:%s", x.fname);
	printf("Surname.....:%s", x.sname);
	printf("Zip code.....:%ld\n", x.zip);
	printf("Place.....:%s", x.place);
	printf("Year of Birth.....:%d\n", x.yob);
}

// Main Function 

void struct2(void)
{
	printf("First Name	:");
	fgets(adress.fname, MAX, stdin);
	printf("Surname		:");
	fgets(adress.sname, MAX, stdin);
	printf("ZIP Code	:");
	do
	{
		scanf("%5ld", &adress.zip);
	}while(getchar()!='\n');
	printf("Place		:");
	fgets(adress.place, MAX, stdin);
	printf("Year of Birth	:");
	do
	{
		scanf("%4d", &adress.yob);
	}while(getchar()!='\n');

	output(adress); // Call
}

int ex21(void)
{
	struct2();
	return 0;
}
