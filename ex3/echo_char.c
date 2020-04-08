#include <stdio.h>
#include <stdlib.h>

void echo(void)
{
	int c;

	while( (c=getchar())!='.')
		putchar(c);
}

int ex31(void)
{
	echo();
	printf("\n");
	return EXIT_SUCCESS;
}

