#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __unix__
	#define clrscr() fprintf(stdout, "\x2b[2J")
#else
	#include <stdlib.h>
	#define clrscr() system("cls")
#endif
int time1(void)
{
	time_t t;

	time(&t);
	while(1)
	{
		clrscr();
		fprintf(stdout, "%ld\n",t);
		fprintf(stdout, "Exit with <STRG><C> or <STRG><D>...\n");
		time(&t);
	}
	return EXIT_SUCCESS;
}

int ex56(void)
{
	return time1();
}
