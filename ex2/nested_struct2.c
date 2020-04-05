#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30

// counting entered dates
static int dates = 0;

// counting entered adresses
static int nr = 0;

struct time
{
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
};

struct date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

struct adres
{
	char fname[MAX];
	char lname[MAX];
	long zip;
	char place[MAX];
	int yob;
}adress[100];

struct meeting
{
	struct date d;
	struct time t;
	struct adres a;
}meet[20];

void newdate(struct meeting *meet)
{
	int select, ret;
	char search_name[MAX];

	printf("Day......:");
	scanf("%u", &meet[dates].d.day);
	printf("Month....:");
	scanf("%u",&meet[dates].d.month);
	printf("Year.....:");
	scanf("%d",&meet[dates].d.year);
	printf("------------------------\n");
	printf("Hour.....:");
	scanf("%u",&meet[dates].t.hour);
	printf("Minute...:");
	scanf("%u",&meet[dates].t.minute);
	printf("second...:");
	scanf("%u",&meet[dates].t.second);
	printf("------------------------\n");

	printf("\n Meeting with:"
	       "\n -1- New adress \n -2- Existing adress\n"
	       "Choice > ");
	do
	{
		scanf("%d", &select);
	}while(getchar()!='\n');

	if(select==1)
	{
		printf("First Name......:");
		fgets(meet[dates].a.fname, MAX, stdin);
		printf("Last Name.......:");
		fgets(meet[dates].a.lname, MAX, stdin);
		printf("Zip Code........:");
		do
		{
			scanf("%5ld",&meet[dates].a.zip);
		}while(getchar()!='\n');
		printf("Place...........:");
		scanf("%s",&meet[dates].a.place);
		printf("Year of Birth...:");
		do
		{
			scanf("%4d",&meet[dates].a.yob);
		}while(getchar()!='\n');

		// Copy new adress in register
		strcpy(adress[nr].fname, strtok(meets[dates].a.fname, "\n"));
		strcpy(adress[nr].lname, strtok(meets[dates].a.lname, "\n"));
		adress[nr].zip=meets[dates].a.zip;
		strcpy(adress[nr].place, strtok(meets[dates].a.place));
		adress[nr].yob = meets[dates].a.yob;
		dates++;
		nr++;
	}
	else
	{
		printf("Please insert last name	:");
		fgets(search_name, MAX, stdin);
		ret=search(strtok(search_name, "\n"));
		if(ret==-1)
		{
			printf("No entry found \n");
			return;
		}
		// Copy adress from register to actuall meeting
		strcpy(meet[dates].a.fname,adress[ret].fname);
		strcpy(meet[dates].a.lname,adress[ret].lname);
		meet[dates].a.zip=adress[ret].zip;
		strcpy(meet[dates].a.place,adress[ret].place);
		meet[dates].a.yob=adress[ret].yob;
		dates++;
	}
}

int search(char *searchname)
{
	int pos, found = 0;

	for(pos=0; pos<=nr; pos++)
	{
		if(strcmp(adress[pos].lname,searchname)==0)
		{
			found=1;
			break;
		}
	}
	if(found)
		return pos;
	else
		return -1;
}

// TODO listdate(), replacedate(), sortdate(), input, output, sortadress and main
