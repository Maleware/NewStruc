#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 255

int searchstringf(int count, char *path)
{
	FILE *f;
	char searchstring[BUF], buffer[BUF];
	int counter = 1;

	if(count<2)
	{
		fprintf(stderr, "Usage: %s file\n", path);
		return EXIT_FAILURE;
	}
	f=fopen(path, "r");
	if(f==NULL)
	{
		printf("Error with fopen()...\n");
		return EXIT_FAILURE;
	}
	printf("What are you looking for in %s >", path);
	scanf("%s", searchstring);
	printf("\n");
	while( fgets(buffer,BUF,f) !=NULL)
	{
		if(strstr(buffer,searchstring) != 0)
			printf("Line %d : %s", counter, buffer);
		counter++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int ex312(void)
{
	int count;
	char path[BUF];
	printf("Paht of the file you want to search in: >");
	scanf("%s", path);
	count=strlen(path);
	return searchstringf(count,path);
}
