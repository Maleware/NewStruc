#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_numbers(int number, ...)
{
	va_list ptr;
	int num;
	int i;

	fprintf(stdout, "%d numbers will be printed\n", number);
	va_start(ptr,number);
	for(i=1; i<= number; i++)
	{
		num=va_arg(ptr, int);
		fprintf(stdout, "%d\t",num);
	}
	fprintf(stdout,"\n");
	va_end(ptr);
}

int vargs2(void)
{
	print_numbers(4,3,2,4,7);
	print_numbers(6,11,22,33,44,55,66);
	return EXIT_SUCCESS;
}

int ex51(void)
{
	return vargs2();
}
