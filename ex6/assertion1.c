#include <stdio.h>
#include <stdlib.h>
#define NDEBUG
#include <assert.h>

int divide(int num1, int num2)
{
	assert( (num1 >= 0 && num1 >= num2) && (num2 >= 0) );
	return num1 / num2;
}

int assert1(void)
{
	fprintf(stdout, "%d / %d = %d\n",5,2,divide(5,2));
	fprintf(stdout, "%d / %d = %d\n",3,4,divide(3,4));
	fprintf(stdout, "%d / %d = %d\n",4,4,divide(4,4));
	return EXIT_SUCCESS;
}

int ex60(void)
{
	return assert1();
}
