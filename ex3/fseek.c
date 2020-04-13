#include <stdlib.h>
#include <stdio.h>

int fseekf(void)
{
	FILE *source, *error;
	int c=0;
	char file[20];
	long pos = 0;

	printf("Which file to open? > ");
	scanf("%s", file);
	fflush(stdin);

	if( (source=fopen(file, "a+")) == NULL)
	{
		if( (error=fopen("testdata/error.log","a+")) != NULL )
		{
			fprintf(error, "Unable to open %s", file);
			fprintf(stderr, "Unable to open %s", file);
			return EXIT_FAILURE;
		}
		fprintf(stderr, "Unable to open %s", file);
		return EXIT_FAILURE;
	}	
	
	// To end input, type *
	printf("Insert desired input, end with <*>\n");
	while( (c=getc(stdin)) != '*' )
			putc(c,source);

	// point to the beginning of file
	fseek(source, 0L, SEEK_SET);

	// print full file on display
	printf("\n Printout of full file: \n");
	while( (c=getc(source)) !=EOF)
		putc(c, stdout);

	// Go back 10 chars and print the last 10 chars
	printf("\n Last 10 chars: \n");
	fseek(source, -10L, SEEK_CUR);
	while( (c=getc(source)) != EOF)
		putc(c, stdout);

	// User decides how many chars to go back
	printf("\n number of chars to go back (From data start) \n");
	scanf("%ld", &pos);
	fflush(stdin);

	fseek(source, 0L, SEEK_SET);
	fseek(source, pos, SEEK_CUR);

	while( (c=getc(source)) !=EOF)
		putc(c,stdout);
	return EXIT_SUCCESS;
	
}

int ex38(void)
{
	return fseekf();
}
