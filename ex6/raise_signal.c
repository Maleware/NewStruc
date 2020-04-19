#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfunct(int sig)
{
	if(sig == SIGINT)
		fprintf(stdout, "SIGINT triggerd...\n");
}

int raisesig(void)
{
	signal(SIGINT, sigfunct);
	fprintf(stdout, "Trigger SIGINT with <ENTER> \n");
	getchar();
	// trigger SIGINT
	raise(SIGINT);
	return EXIT_SUCCESS;
}

int ex612(void)
{
	return raisesig();
}
