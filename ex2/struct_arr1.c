#include "../output.h"
#include "../input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct index
{
	int page;
	char title[30];
};

void struct_array1(void)
{
	int i;
	struct index lib[3];

	lib[0].page=312;
	strcpy(lib[0].title, "Structure array");
	lib[1].page=320;
	strcpy(lib[1].title, "Structure within structure");
	lib[2].page=900;
	strcpy(lib[2].title, "Appendix");

	for(i=0; i<3; i++)
		printf("page %3d\t %-30s\n", lib[i].page, lib[i].title);
}

int ex25 (void)
{
	struct_array1();
	return 0;
}
