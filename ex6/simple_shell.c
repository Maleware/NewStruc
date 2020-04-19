#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>

#define MAX 255
#define OK 0

jmp_buf restart;

void ctrlc(int sig)
{
	signal(sig, ctrlc);
	// back to commandline
	longjmp(restart, 1);
	return;
}

int simpleshell(void)
{
	char *command;
	// install signalhandler
	signal(SIGINT, ctrlc);

	if(setjmp(restart) != 0)
		fprintf(stdout, "Restarted Shell...\n\n");
	else
		fprintf(stdout, "Started shell...\n\n");

	for(;;) // here you can do what ever you want
	{
		char buffer[MAX];
		fprintf(stdout, "$->");
		fgets(buffer, MAX, stdin);
		command = strtok(buffer, "\n");

		if( strcmp(command, "test") == OK)
			fprintf(stdout, "Command was \"Test\"\n\n");
		else if( strcmp(command, "help") == OK)
			fprintf(stdout, "Command \"Help\"\n\n");
		else if( strcmp(command, "exit") == OK)
			exit (EXIT_SUCCESS);
		else
		{
			fprintf(stderr, "Unknown command...\n");
			fprintf(stdout, "Commands: test, help and exit");
		}

	}
	return EXIT_SUCCESS;
}

int ex611(void)
{
	return simpleshell();
}
