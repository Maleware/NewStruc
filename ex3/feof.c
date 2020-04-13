#include <stdlib.h>
#include <stdio.h>

void feofc(void)
{
	int c;

	while( (c=getc(stdin)) )
	{
		if(feof(stdin)!=0)
			break;
		else
			putc(c,stdout);
	}
}

int ex36(void)
{
	feofc();
	return EXIT_SUCCESS;
}
