#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random2(void)
{
	int rannum, i, startpoint;

	fprintf(stdout, "Input any number :>");
	do
	{
		scanf("%d", &startpoint);
	}while(getchar() != '\n');
	srand(startpoint);
	for(i=0; i<5; i++)
		fprintf(stdout, "Randomnumber: %d\n", rannum=rand());
	return EXIT_SUCCESS;
}

int ex66(void)
{
	return random2();
}
