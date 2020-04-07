#include <stdio.h>
#include <stdlib.h>

void fopen1(void)
{
	FILE *data;

	// Insert here abitrary pathes of your data
	data=fopen("testdata/test.txt", "r");
	if(NULL==data)
	{
		printf("Unable to open data. Wrong path?\n");
	}
}

int ex30(void)
{
	fopen1();
	return EXIT_SUCCESS;
}
