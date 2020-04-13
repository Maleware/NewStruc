#include <stdlib.h>
#include <stdio.h>

#define FILES "../testdata/test.txt"

int grownfile(void)
{
	FILE *fp;
	int c;

	fp = fopen(FILES, "r");
	if(fp==NULL)
	{
		fprintf(stderr, "Unable to open %s \n", FILES);
		return EXIT_FAILURE;
	}
	while(1)
	{
		while( (c=fgetc(fp)) ) // read char wise
		{
			if(c==EOF) // if end of file
				ungetc(c,fp); // return last char
			else
				fputc(c,stdout); // print
		}

	}
	// never visible
	fclose(fp);
	return EXIT_SUCCESS;
}

int ex37(void)
{
	int r=0;
	r=grownfile();
	return r;
}
