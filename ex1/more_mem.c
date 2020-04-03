#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 8192

void moremem(void)
{
	char* buffer;
	int reserved=0;
	int i;
	static size_t len = BUF; // memory allocation

	buffer = malloc(sizeof("Hello World"));
	strcpy(buffer, "Hello World");

	while(reserved != BUF && len !=0)
	{
		buffer = realloc(buffer, len);
		// no allocation possible
		if (buffer == NULL)
		{
			len/=2; //Try with the half
		}
		else
		{
			reserved += len;
		}
	}

	for (i=0; i < reserved; i++)
		buffer[i]='x';
	buffer[i]='\0';
	printf("\n%s\n", buffer);
	return EXIT_FAILURE;
}

int ex14(void)
{
	moremem();
	return 0;
}
