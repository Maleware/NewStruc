#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 255

// Change as u need
const char seperation[]=",;.;\";\';' '";

int searchword(int count, char *path)
{
	FILE *f;
	char searchstring[BUF];
	char buffer[BUF], buffer_bak[BUF];
	int counter=1;
	char *word;

	if(count<2)
	{
		fprintf(stderr, "Usage : %s file\n", path);
		return EXIT_FAILURE;
	}
	f=fopen(path, "r");
	if(f == NULL)
	{
		printf("Error with fopen()...\n");
		return EXIT_FAILURE;
	}
	printf("Whats the word u looking for in %s: >", path);
	scanf("%s", searchstring);
	printf("\n");

	while (fgets(buffer,BUF,f) != NULL)
	{
		strcpy(buffer_bak, buffer);
		word=strtok(buffer, seperation);
		while(word != NULL)
		{
			if( strcmp(word, searchstring) == 0 )
				printf("Line %d : %s", counter,buffer_bak);
		word = strtok(NULL,seperation);
		}
		counter++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int ex313(void)
{
	int count=0;
	char path[BUF];

	printf("In which file you want to search?: >");
	scanf("%s", path);
	count=strlen(path);
	return searchword(count,path);
}

