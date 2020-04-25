#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

struct zips
{
	char place[MAX];
	unsigned int zip;
};

struct zips zipcode[100];
static int N;


// init structure
void init(void)
{
	N=0;
	zipcode[N].zip=0;
	strcpy(zipcode[N].place, "init");
}

void instert(unsigned int p, char *o)
{
	zipcode[++N].zip = p;
	strcpy(zipcode[N].place, o);
}

void searching(unsigned int key)
{
	int i;
	for(i=0; i<=N; i++)
	{
		if(zipcode[i].zip == key)
		{
			fprintf(stdout, "Place to ZIP-Code %d: %s\n", key, zipcode[i].place);
			return;
		}
	}
	fprintf(stdout, "For value %d no ZIP-Code was found...\n", key);
}

int simple_search(void)
{
	int select;
	unsigned int search, post;
	char new_place[MAX];
	init();

	do
	{
		fprintf(stdout, "\n\t-1- Search for ZIP-Code"
				"\n\t-2- Add ZIP-Code"
				"\n\t-3- End \n\n");
		do
		{
			scanf("%d", &select);
		}while(getchar() != '\n');

		if(select == 1)
		{
			fprintf(stdout, "Which ZIP-Code you are looking for? \n");
			do
			{
				scanf("%u", &search);
			}while(getchar() != '\n');
			searching(search);
		}
		else if(select == 2)
		{
			fprintf(stdout, "New ZIP-Code: \n");
			do
			{
				scanf("%u", &post);
			}while(getchar() != '\n');
			fprintf(stdout, "Place relating to ZIP-Code: \n");
			fgets(new_place, MAX, stdin);
			instert(post, strtok(new_place, "\n"));
		}
	}while(select != 3);
	return EXIT_SUCCESS;
}

int ex87(void)
{
	return simple_search();
}
