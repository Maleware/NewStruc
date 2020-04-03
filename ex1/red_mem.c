#include "../input.h"
#include "../output.h"
#include <stdio.h>
#include <stdlib.h>
#define MIN_LEN 256

void red_mem(void)
{
	int* ptr;
	char jn;
	static size_t len=8192; // Reserving memory

	do
	{
		ptr = malloc(len);
		// Memory can not be allocated
		if (ptr==NULL)
		{
			len /= 2;
			ptr = malloc(len);
			if(ptr==NULL)
			{
				printout("No memory was allocated"
					 "Try again? (j/n) ");
				scanf("%c", &jn);
				fflush(stdin);
			}
		}
		else
			break; // Memory was allocated
	}while(jn != 'n' && len > MIN_LEN);

	if(len <= MIN_LEN)
		printout("Memory allocated");
}

int ex13(void)
{
	red_mem();
	return 0;
}
