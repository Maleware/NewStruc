#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int add(int numbers, ...)
{
	va_list ptr;
	int number=0;

	va_start(ptr, numbers);
	do
	{
		number = va_arg(ptr, int);
		numbers += number;
	}while(number != 0);

	va_end(ptr);
	return numbers;
}

int vargs1(void)
{
	int erg;
	fprintf(stdout, "%d \n", add(11,12,13,0));
	fprintf(stdout, "%d \n", add(99,66,33,22,11,0));
	erg = add(10,13,11,0) + add(9,8,11,0);
	fprintf(stdout, "%d \n",erg);
	return EXIT_SUCCESS;
}

int ex50(void)
{
	return vargs1();
}
