#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>

struct test1
{
	char a;
	int b;
	double c;
};

union test2
{
	char a;
	int b;
	double c;
};


void union1(void)
{
	printf("size of struct: %ld Bytes\n",sizeof(struct test1));
	printf("size of union:  %ld Bytes\n",sizeof(union test2));
}

int ex28(void)
{
	union1();
	return EXIT_SUCCESS;
}
