#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random3(void)
{
	int rannum, i;

	srand(time(NULL));
	for(i=0; i<5; i++)
		fprintf(stdout, "Randomnumber: %d\n", rannum=rand()%10+1);
	return EXIT_SUCCESS;
}

int ex67(void)
{
	return random3();
}
