#include <stdio.h>
#include <stdlib.h>

char string[]=
{
	"This is a string for the Testfile \n"
	"This line is a placeholder \n"
	"This line shall be changed\n"
	"It could follow a lot more lines \n"
};

void create_textfile(void)
{
	FILE *out=fopen("testdata/create.txt", "w+");
	if(NULL == out)
		exit (EXIT_FAILURE);
	fputs(string, out);
	fclose(out);
}

int tempfile(void)
{
	FILE *in, *out;
	char line[80], tmp[255];
	int line_nr=1;

	// Create file with value string
	create_textfile();

	// Open file for changing
	in = fopen("testdata/create.txt", "r");
	if(NULL == in)
	{
		fprintf(stderr,"Unable to create file...\n");
		return EXIT_FAILURE;
	}
	// tmp =tmpnam(NULL);  create temporal file, do not use since dangerours
	// open temp file to write
	// out=fopen(tmp, "w");	
	mkstemp(tmp);
	out = fopen(tmp, "w");
	
	if(NULL == out)
	{
		fprintf(stderr,"Unable to open temp-file...\n");
		return EXIT_FAILURE;
	}
	// read line wise from file
	// and write into tmp file
	while(NULL !=fgets(line, 80, in))
	{
		//changing third line
		if(line_nr == 3)
			fputs("Changed line\n", out);
		else
			fputs(line, out);
		line_nr++;
	}
	fclose(in);
	fclose(out);
	remove("testdata/create.txt"); // delete original file
	rename(tmp, "testdata/create.txt"); // rename tmp file
	printf("\n\nDone...\n\n");
	return EXIT_SUCCESS;
}

int ex317(void)
{
	return tempfile();
}
