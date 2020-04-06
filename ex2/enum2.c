#include "../input.h"
#include "../output.h"
#include <stdlib.h>
#include <stdio.h>

enum BOOL {FALSE, TRUE};

void enum2(void)
{
	int number;
	printf("Type a number (0-9) >");
	if((scanf("%d", &number)) == FALSE )
	{	
		printf("No number fucker\n");
		fflush(stdin);
	}
	else
	{
		printf("thx\n");
		fflush(stdin);
	}

	if( (number == 7) == TRUE)
	printf("Seven is my favourite\n");
	fflush(stdin);
}

int ex29(void)
{
	enum2();
	return EXIT_SUCCESS;
}
