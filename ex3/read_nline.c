#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 255

char temp[BUF];
char buffer[BUF];

// read out the n-th line
char *getsline_number(int n, FILE *file)
{
	int i;

	for(i=0; i<n-1; i++)
		if(fgets(temp, BUF, file) == NULL)
			// read till n'th line
			return NULL; // Line not existing
	if(fgets(buffer, BUF, file) == NULL)
		return NULL;
	return buffer;
}

int readnline(int count, char *path)
{
	FILE *f;
	unsigned int line;
	char *linenr;

	if(count<2)
	{
		fprintf(stderr, "Usage: %s file\n",path);
		return EXIT_FAILURE;
	}
	f=fopen(path,"r");
	if(f==NULL)
	{
		printf("Error while open file");
		return EXIT_FAILURE;
	}
	printf("Which line to read? >");
	scanf("%u", &line);

	linenr=getsline_number(line, f);
	if(linenr==NULL)
	{
		fprintf(stderr, "Error while reading"
				" %d'th line. \n", line);
		return EXIT_FAILURE;
	}
	printf("Row %d : %s\n", line, linenr);
	return EXIT_SUCCESS;
}

int ex310(void)
{
	int count;
	char path[BUF];

	printf("Which file to open? >");
	scanf("%s", path);
	count=strlen(path);
	return readnline(count, path);

}
