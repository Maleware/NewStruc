#include <stdio.h>
#include <stdlib.h>

#define NUMITEMS 4

char *names[4] = 
{
	"Jens", "Fatma", "Gismo", "Jonathan"
};

int form(void)
{
	int loop;
	char temp[4][80];
	char name[20];
	int age;
	long wage;


	// We create Name, age and wage. Age and wage 
	// are created with random numbers. Writing data 
	// with sprintf to tmp
	for(loop=0; loop <NUMITEMS; ++loop)
	{
		sprintf(temp[loop], "%s %d %ld",
		names[loop], rand()%20+18, rand()+27500L);
	}

	// We create a header
	printf("%4s | %-20s | %5s | %9s\n",
		"#", "Name","Age","Wage");
	printf("----------------------------------------------"
		"-------------\n");

	// read data formated with sscanf from tmp
	for(loop=0; loop < NUMITEMS; ++loop)
	{
		sscanf(temp[loop], "%s %d %ld",(char *)&name, &age,&wage);
		printf("%4d | %-20s | %5d  | %9ld\n",
				loop+1, name, age, wage);
	}
	return EXIT_SUCCESS;
}

int ex318(void)
{
	return form();
}
