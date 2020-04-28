#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4096

void init_next(char *, int);
void kmpSearch(char *, char *);
int next[MAX];

// i = position in Text
// j = position in pattern

void kmpSearch(char *pattern, char *text)
{
	int i=0, j=0;
	int m=strlen(pattern); // length pattern
	int n=strlen(text);    // length text

	init_next(pattern, m); // Table for next calc

	while(i<n) // as long as we are not at the end of text
	{
		while(j>=0 && text[i] != pattern[j])
			j=next[j];
		i++;
		j++;
		if (j==m)
		{
			fprintf(stdout, "Found at position %d\n", i-j);
			j=next[j];
		}
	}
}

void init_next(char *pattern, int m)
{
	int i,j;

	i=0;
	j= next[0] = -1;
	
	while (i<m) // as long as i is smaller than m search string
	{
		while(j > -1 && pattern[i] != pattern[j])
			j=next[j];
		i++;
		j++;
		(pattern[i] == pattern[j]) ? (next[i]=next[j]) : (next[i]=j);
	}
}

int kmp_search(void)
{
	kmpSearch("alalas", "lu lalalalala lule lulalalas");
	return EXIT_SUCCESS;
}

int ex812(void)
{
	return kmp_search();
}
