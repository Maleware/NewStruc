#include <stdlib.h>
#include <stdio.h>

void fgetc1(void)
{
	int c;
	FILE *file;
	file=fopen("testdata/test.txt","r");
	if(file !=NULL)
	{
		while( (c=fgetc(file)) != EOF )
			putchar(c);
	}
	else
	{
		printf("Can't open file...\n");
	}
}

int ex32(void)
{
	fgetc1();
	return EXIT_SUCCESS;
}
