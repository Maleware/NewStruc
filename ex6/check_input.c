#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CHARS 20

void chompstr(char *str)
{
	size_t p=strlen(str);
	// override \n with \0
	str[p-1]='\0';
}

void is_long(char *str)
{
	static long val;
	char *stop_ptr=NULL;

	val = strtoul(str, &stop_ptr, 10);
	if(errno = ERANGE)
	{
		fprintf(stderr, "Value under-/overflow\n");
		exit (EXIT_FAILURE);
	}
	if(!val)
	{
		fprintf(stderr, "Value not convertable...\n");
		exit (EXIT_FAILURE);
	}
	if(*stop_ptr)
	{
		fprintf(stderr, "No correct long value: %s \n", str);
		fprintf(stderr, "Error in convertion at pos: %s \n", stop_ptr);
		fprintf(stderr, "Converted --> %ld \n", val);
	}
	else
		fprintf(stdout, "Wohoo! Correct long value: %ld \n", val);
}


void is_double(char *str)
{
	static double val;
	char *stop_ptr = NULL;

	val = strtod(str, &stop_ptr);
	if(errno = ERANGE)
	{
		fprintf(stderr, "Value under-/overflow \n");
		exit (EXIT_FAILURE);
	}
	if(!val)
	{
		fprintf(stderr, "Value not convertable...\n");
		exit (EXIT_FAILURE);
	}
	if(*stop_ptr)
	{
		fprintf(stderr, "No correct double value: %s \n", str);
		fprintf(stderr, "Error in convertion at pos: %s \n", stop_ptr);
		fprintf(stderr, "Converted --> %lf\n", val);
	}
	else
		fprintf(stdout, "Wohoo! Correct double value: %lf\n", val);
}

int checkinput(void)
{
	char val[CHARS];
	// test long value
	fprintf(stdout, "Please insert long value :>");
	fgets(val, CHARS, stdin);
	chompstr(val);
	is_long(val);
	// same with double
	fprintf(stdout, "Please insert double value :>");
	fgets(val, CHARS, stdin);
	chompstr(val);
	is_double(val);

	return EXIT_SUCCESS;
}

int ex63(void)
{
	return checkinput();
}
