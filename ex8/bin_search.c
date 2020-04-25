#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

struct zipc
{
	char place[MAX];
	unsigned int zip;
};

struct zipc zipcodes[100];
static int N;

// init
void initz(void)
{
	N=0;
	zipcodes[N].zip = 0;
	strcpy(zipcodes[N].place, "dummy");
}

void insertbs(unsigned int p, char *o)
{
	zipcodes[++N].zip = p;
	strcpy(zipcodes[N].place, o);
}

int cmp_uinteger(const void *value1, const void *value2)
{
	const struct zipc *p1 = value1;
	const struct zipc *p2 = value2;
	if(p1->zip > p2->zip)
		return 1;
	else if(p2->zip > p1->zip)
		return (-1);
	else
		return 0;
}

int binary_search(unsigned int key)
{
	int l=1;
	int r=N;
	int x;

	while(r >= 1)
	{
		x=(l+r) >> 1;
		if(key < zipcodes[x].zip) // smaller?
			r=x-1; // Right side is not interresting anymore
		else
			l=x+1; // Left side is not interresting anymore
		if(key == zipcodes[x].zip)
			return x; // found, return position
	}
	return -1;
}

int bin_search(void)
{
	int select, ret;
	unsigned int search, post;
	char new_place[MAX];

	initz();
	do
	{
		fprintf(stdout, "\n\t-1- Search ZIP"
				"\n\t-2- Insert ZIP"
				"\n\t-3- END"
				"\nChoose....>");
		do
		{
			scanf("%d", &select);
		}while(getchar() != '\n');

		if(select == 1)
		{
			fprintf(stdout, "ZIP-Code you are looking for...>");
			do
			{
				scanf("%u", &search);
			}while(getchar() != '\n');
			ret=binary_search(search);
			if(ret == -1)
				fprintf(stderr, "No match found....\n");
			else
				fprintf(stdout, "Matching place to %d is %s", search, zipcodes[ret].place);
		}
		else if(select == 2)
		{
			fprintf(stdout, "New ZIP-Code...>");
			do
			{
				scanf("%5u", &post);
			}while(getchar() != '\n');

			fprintf(stdout, "Corresponding place...>");
			fgets(new_place, MAX, stdin);
			insertbs(post, strtok(new_place, "\n"));
			qsort(zipcodes, N, sizeof(unsigned int), cmp_uinteger);
		}
	}while(select !=3);
	return EXIT_SUCCESS;
}

int ex88(void)
{
	return bin_search();
}
