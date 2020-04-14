#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifdef __unix__
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
	#include <io.h>
	#include <sys\stat.h>
#endif

#define MAXADRESSES 10
#define MAX 30

struct customer
{
	char name[MAX];
	char fname[MAX];
	int custnr;
	char place[MAX];
	char road[MAX];
	int number;
	int prefix;
	int phone;
};

struct customer c[MAXADRESSES];
static int counter=0;

void newcustomer(void)
{
	int fh;

	if(counter==MAXADRESSES)
		fprintf(stderr, "No memory available...\n");
	else
	{
		printf("Last Name........:");
		fgets(c[counter].name, MAX, stdin);
		printf("First name.......:");
		fgets(c[counter].fname, MAX, stdin);
		c[counter].custnr=counter;
		printf("City.............:");
		fgets(c[counter].place, MAX, stdin);
		printf("Road.............:");
		fgets(c[counter].road, MAX, stdin);
		printf("Number...........:");
		do
		{
			scanf("%d", &c[counter].number);
		}while(getchar() != '\n');
		printf("Prefix...........:");
		do
		{
			scanf("%d", &c[counter].prefix);
		}while(getchar() != '\n');
		printf("Phone number.....:");
		do
		{
			scanf("%d", &c[counter].phone);
		}while(getchar() != '\n');

		if( (fh=open("testdata/customer.dat", O_CREAT | O_RDWR) ) == -1)
			printf("Unable to open testdata/customer.dat\n");
		else if( (write(fh, &c, sizeof(c))) == -1)
			printf("Unable to write testdata/customer.dat\n");
		else
			counter++;

	}
}

void readc(void)
{
	int fh;
	int num=0;

	printf("Please enter customer number	:");
	do
	{
		scanf("%d", &num);
	}while(getchar() != '\n');

	if( (fh=open("testdata/customer.dat", O_RDONLY)) == -1)
	{
		perror("Unable to open \"testdata/customer.dat\"\n");
		exit (EXIT_FAILURE);
	}
	read(fh, &c, sizeof(c));
	printf("\n\n");
	printf("Last name........:%s\n",c[num].name);
	printf("First name.......:%s\n",c[num].fname);
	printf("Customer number..:%d\n",c[num].custnr);
	printf("City.............:%s\n",c[num].place);
	printf("Road.............:%s\n",c[num].road);
	printf("Number...........:%d\n",c[num].number);
	printf("Prefix...........:%d\n",c[num].prefix);
	printf("Phonenumber......:%d\n",c[num].phone);
}

int read3(void)
{
	int select;

	do
	{
		printf("\t -1-: Insert new customer \n\n");
		printf("\t -2-: Print customer keyword customer number \n\n");
		printf("\t -3-: Exit \n\n");
		printf("\t What you want to do? : >");
		do
		{
			scanf("%d", &select);
		}while(getchar() != '\n');
		switch(select)
		{
			case 1: newcustomer();
				break;
			case 2: readc();
				break;
			case 3: printf("Bye \n\n");
				break;
			default: printf("Please insert valid choice...\n");
				 break;
		}	
	}while(select != 3);
	return EXIT_SUCCESS;
}

int ex322(void)
{
	return read3();
}

