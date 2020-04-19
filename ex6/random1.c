#include <stdio.h>
#include <stdlib.h>

int random1(void)
{
	int rannum, i;

	for(i=0; i<5; i++)
		fprintf(stdout, "Randomnumber: %d\n", rannum=rand());
	return EXIT_SUCCESS;
}

int ex65(void)
{
	return random1();
}
