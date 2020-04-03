#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index
{
	int page;
	char title[30];
};

void struc1(void)
{
	struct index lib;

	lib.page=23;
	strcpy(lib.title, "C-Programming");
	printf("%d, %s\n",lib.page, lib.title);
}

int ex20(void)
{
	struc1();
	return 0;
}
