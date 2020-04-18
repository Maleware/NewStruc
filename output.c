#include <stdio.h>
#include "header/output.h"


int indentlevel = 0;

void indentpush(void)
{
	++indentlevel;
}
void indentpop(void)
{
	if(indentlevel > 0)
		--indentlevel;
}

void printerr(const char* str)
{
	fprintf(stderr, "Error: %s\n\n", str);
}

void printout(const char* str)
{
	int i = 0;
	while (i < indentlevel)
	{
		printf("\t");
		++i;
	}
	printf("%s\n", str);
}
