#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX 50

void strxcat(int n_strings, ...)
{
	va_list ptr;
	char *source, *target, *p;

	va_start(ptr, n_strings);
	// now point on target string
	target = va_arg(ptr, char *);
	p = target;
	// end of target string
	target+=strlen(target);
	if( (target-p) > MAX)
	{
		fprintf(stderr, "Reached maximum string length \n\n");
		exit (EXIT_FAILURE);
	}
	while(--n_strings > 0)
	{
		// read source
		source = va_arg(ptr, char *);
		while(*source)
		{
			*target++=*source++;
			if( (target-p) > MAX)
			{
				fprintf(stderr, "Reached maximum string length \n\n");
				exit (EXIT_FAILURE);
			}
		}
	}
	*target='\0';
}

int strxcatm(void)
{
	char string[MAX] = "Test : ";
	char string2[] = " and";

	strxcat(3, string, "Hello", "World");
	fprintf(stdout,"%s\n",string);

	strxcat(5,string,string2," a"," additional", " test");
	fprintf(stdout,"%s\n", string);

	// well known mistake
	strxcat(4, string, " Overflow", " of", " MAX");
	return EXIT_SUCCESS;
}

int ex52(void)
{
	return strxcatm();
}
