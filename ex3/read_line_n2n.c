#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 255

char temp[BUF];
char buffer[BUF];
int i; // row counter

char *getsline_number1(int n1, int n2, FILE *file)
{
	for(i=0; i<n1-1; i++)
		// read till n'th line
		if(fgets(temp,BUF,file)==NULL)
			return NULL; // line is not existing
	// now we can start to read
	printf("\n\n");
	for(i=n1; i<=n2; i++)
	{
		if(fgets(buffer,BUF,file)==NULL)
			// Stream is now at the n'th line
			return NULL; //line is not existing
		printf("Line %d : %s", i, buffer);
	}
	return buffer;
}

int readlinn2n(int count, char *path)
{
	FILE *f;
	int line1, line2;
	char *linenr;

	if(count<2)
	{
		fprintf(stderr, "Usage : %s file\n", path);
		return EXIT_FAILURE;
	}
	f=fopen(path,"r");
	if(f==NULL)
	{
		printf("Error with fopen()...\n");
		return EXIT_FAILURE;
	}
	printf("Which line you want to start with? >");
	scanf("%d", &line1);
	printf("\n Which line you want to stop with? >");
	scanf("%d", &line2);

	if(line2<line1)
	{
		fprintf(stderr, "target row can't be taller"
				"than starting row\n");
		return EXIT_FAILURE;
	}

	linenr=getsline_number1(line1,line2, f);

	if(linenr == NULL)
	{
		fprintf(stderr, "Error while reading "
				"%d'th line \n", i);
		return EXIT_FAILURE;
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int ex311(void)
{
	int count=0;
	char path[255];

	printf("Insert desired filepath: >");
	scanf("%s", path);
	count=strlen(path);
	return readlinn2n(count, path);
}

