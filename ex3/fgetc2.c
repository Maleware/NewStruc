#include <stdio.h>
#include <stdlib.h>

void read_char(FILE *stream)
{
	int c;

	while( (c=fgetc(stream)) != EOF)
		putchar(c);
}

int fgetc2(int count, char *path)
{
	FILE *file;
	char filename[255];

	// if file wasn't given by starting the programm
	if(count<2)
	{
		printf("Which file to open? >");
		fgets(filename, 255, stdin);
		file=fopen(filename, "r");

		if(file != NULL)
			read_char(file);
		else
		{
			printf("Error by open the file of %s\n", filename);
			return EXIT_FAILURE;
		}
	}
	else
	{
		file=fopen(path,"r");
		if(file != NULL)
			read_char(file);
		else
		{
			printf("Unable to open %s \n",path);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int ex33(void)
{
	int r=0, ccount=0;
	char path[255];

	printf("Which file should be opend? > ");
	fgets(path, 255, stdin);
	if( (path[0]) == '\n' )
		ccount=1;
	else
		ccount=2;
	r=fgetc2(ccount,path);
	return r;
}
