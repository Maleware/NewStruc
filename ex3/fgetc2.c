#include <stdio.h>
#include <stdlib.h>

void read_char(FILE *stream)
{
	int c;

	while( (c=fgetc(stream)) != EOF)
		putchar(c);
}

int fgetc2(int argc, char **argv)
{
	FILE *file;
	char filename[255];

	// if file wasn't given by starting the programm
	if(argc<2)
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
		file=fopen(argv[1],"r");
		if(file != NULL)
			read_char(file);
		else
		{
			printf("Unable to open %s\n",argv[1]);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int ex33(int argc, char **argv)
{
	int r=0;
	r=fgetc2(argc, argv);
	return r;
}
