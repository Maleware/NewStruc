#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int value, int length)
{
	char *ret=(char *) malloc(length+1 * sizeof(char));
	int i;

	for(i=0; i<length; i++)
	{
		ret[length-i-1] = (value % 10) + 48;
	        value=value/10;	
	}
	ret[length]='\0';
	return ret;
}

int myitoa(void)
{
	fprintf(stdout, "%s\n", my_itoa(1234,4));
	fprintf(stdout, "%s\n", my_itoa(5432,6));
	return EXIT_SUCCESS;
}

int ex64(void)
{
	return myitoa();
}
