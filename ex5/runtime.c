#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int runtime(void)
{
	clock_t prgstart, prgend;
	int c=0;

	prgstart=clock();
	fprintf(stdout, "Input anything and stop with enter >");
	while(getchar() != '\n')
		putchar(c);
	prgend=clock();
	fprintf(stdout, "Runtime of programm: %.2f seconds\n",(float)(prgend-prgstart) / CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}

int ex59(void)
{
	return runtime();
}
