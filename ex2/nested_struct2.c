#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30

//TODO Allow passing of input and bring up to security level

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
	int year;
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

int searchname(char *searchname)
{
	int pos, found=0;

	for(pos=0; pos <=nr; pos++)
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

void newdate(struct meeting *nmeet)
{
	int select, ret;
	char search_name[MAX];

	printf("Day......:");
	scanf("%u", &nmeet[dates].d.day);
	printf("Month....:");
	scanf("%u",&nmeet[dates].d.month);
	printf("Year.....:");
	scanf("%d",&nmeet[dates].d.year);
	printf("------------------------\n");
	printf("Hour.....:");
	scanf("%u",&nmeet[dates].t.hour);
	printf("Minute...:");
	scanf("%u",&nmeet[dates].t.minute);
	printf("second...:");
	scanf("%u",&nmeet[dates].t.second);
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
		fgets(nmeet[dates].a.fname, MAX, stdin);
		printf("Last Name.......:");
		fgets(nmeet[dates].a.lname, MAX, stdin);
		printf("Zip Code........:");
		do
		{
			scanf("%5ld",&nmeet[dates].a.zip);
		}while(getchar()!='\n');
		printf("Place...........:");
		fgets(nmeet[dates].a.place, MAX, stdin);
		printf("Year of Birth...:");
		do
		{
			scanf("%4d",&nmeet[dates].a.yob);
		}while(getchar()!='\n');

		// Copy new adress in register
		strcpy(adress[nr].fname, strtok(nmeet[dates].a.fname, "\n"));
		strcpy(adress[nr].lname, strtok(nmeet[dates].a.lname, "\n"));
		adress[nr].zip=nmeet[dates].a.zip;
		strcpy(adress[nr].place, strtok(nmeet[dates].a.place, "\n"));
		adress[nr].yob = nmeet[dates].a.yob;
		dates++;
		nr++;
	}
	else
	{
		printf("Please insert last name	:");
		fgets(search_name, MAX, stdin);
		ret=searchname(strtok(search_name, "\n"));
		if(ret==-1)
		{
			printf("No entry found \n");
			return;
		}
		// Copy adress from register to actuall meeting
		strcpy(nmeet[dates].a.fname,adress[ret].fname);
		strcpy(nmeet[dates].a.lname,adress[ret].lname);
		nmeet[dates].a.zip=adress[ret].zip;
		strcpy(nmeet[dates].a.place,adress[ret].place);
		nmeet[dates].a.yob=adress[ret].yob;
		dates++;
	}
}


void listdate(struct meeting *list, int date)
{
	int i;
	for(i=0; i<date; i++)
	{
		printf("Nr. %d",i+1);
		printf("Meeting at %02u.%02u.%04d",
			list[i].d.day, list[i].d.month, list[i].d.year);
		printf("Time: %02u.%02u \n",
			list[i].t.hour, list[i].t.minute);
		printf("with %s %s \n\n", list[i].a.fname, list[i].a.lname);
	}
}

void replacedate(struct meeting *change, int nt)
{
	if(nt <= dates && nt < 20)
	{
		printf("Please insert the new meeting time:\n");
		printf("Day......:");
		scanf("%u",&change[nt].d.day);
		printf("Month....:");
		scanf("%u",&change[nt].d.month);
		printf("Year.....:");
		scanf("%d",&change[nt].d.year);
		printf("--------------------------------------");
		printf("Hour.....:");
		scanf("%u",&change[nt].t.hour);
		printf("Minute...:");
		scanf("%u",&change[nt].t.minute);
	}
	else
		printf("Wrong Input : %d\n",nt);
}

void sortdate(struct meeting *sort, int date)
{
	struct meeting *temp;
	int i,j;

	temp=malloc(sizeof(struct meeting *));
	if(temp == NULL)
	{
		printf("No memory available...\n");
		return;
	}
	for(i=0; i<date; i++)
	{
		for(j=i+1; j<date; j++)
		{
			if(sort[i].d.year>sort[j].d.year)
			{
				*temp=sort[j];
				sort[j]=sort[i];
				sort[i]=*temp;
			}
		}
	}
	printf("Sorted.....\n");
}

void inputstruc(struct adres *new)
{
	unsigned int size;

	printf("First Name......:");
	fgets(new[nr].fname, MAX, stdin);
	size=strlen(new[nr].fname);
	new[nr].fname[size-1]='\0';

	printf("Last Name.......:");
	fgets(new[nr].lname, MAX, stdin);
	size=strlen(new[nr].lname);
	new[nr].lname[size-1]='\0';

	printf("Zip Code........:");
	do
	{
		scanf("%5ld",&new[nr].zip);
	}while(getchar()!='\n');

	printf("Place...........:");
	fgets(new[nr].place, MAX, stdin);

	printf("Year of Birth...:");
	do
	{
		scanf("%4d",&new[nr].yob);
	}while(getchar()!='\n');
	nr++;
}

void outputstruc(struct adres *all)
{
	int i;

	for(i=0; i<nr; i++)
	{
		printf("First Name......: %s\n",all[i].fname);
		printf("Last Name.......: %s\n",all[i].lname);
		printf("Zip Code........: %ld\n",all[i].zip);
		printf("Place...........: %s\n",all[i].place);
		printf("Year of Birth...: %d\n",all[i].yob);
		
		if((!(i%2) && i!=0))
		{
			fflush(stdin);
			printf("\n\t continue with <ENTER>\n\n");
			getchar();
		}
	}
}

void sortadress(struct adres *sort)
{
	struct adres *temp;
	int i,j;

	temp=malloc(sizeof(struct adres *));
	if(NULL==temp)
	{
		printf("No memory available");
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

void nested_struct2(void)
{
	int input, change;
	do
	{
		printf("\t Meeting accountings \n");
		printf("\t--------------------\n \n");
		printf("\t-1- New Meeting \n");
		printf("\t-2- List exisiting meetings \n");
		printf("\t-3- Change Meeting \n");
		printf("\t-4- Sort Meetings \n");
		printf("\t-5- Enter new adress \n");
		printf("\t-6- Print adress \n");
		printf("\t-7- Sort adresses \n");
		printf("\t-8- End Programm \n");
		printf("\t\n Your choice :");
		scanf("%d",&input);
		fflush(stdin);
		getchar();

		switch(input)
		{
			case 1:
				newdate(meet);	break;
			case 2:
				listdate(meet, dates);	break;
			case 3:
				listdate(meet, dates);
				printf("Which meeting to change?");
				scanf("%d",&change);
				replacedate(meet,--change);
				break;
			case 4:
				sortdate(meet, dates);	break;
			case 5:
				inputstruc(adress);	break;
			case 6:
				outputstruc(adress);	break;
			case 7:
				sortadress(adress);	break;
			default:
				break;
		}

	}while(input < 8);
	printf("Bye\n");
}

int ex27(void)
{
	nested_struct2();
	return EXIT_SUCCESS;
}
