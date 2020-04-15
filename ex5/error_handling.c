#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX 8192
enum{WARN, ERROR, EXIT, MISC};

//Stringtable with Error-output

const char *error[] =
{
	"Wrong input\n",
	"Reached maximum input\n",
	"Input was a negative value\n"
};

void errorfu(int ident, const char *format, ...)
{
	va_list vargptr;
	va_start(vargptr,format);
	switch(ident)
	{
		case 0: fprintf(stderr, "\nWarning ");
			vprintf(format,vargptr);
			break;
		case 1: fprintf(stderr, "\nError ");
			vprintf(format,vargptr);
			break;
		case 2: fprintf(stderr, "\nProgram abort ");
			vprintf(format,vargptr);
			break;
		case 3: vprintf(format,vargptr);
			break;
		default: fprintf(stderr, "\nWrong call...\n");
	}
	va_end(vargptr);
}

int errorf(void)
{
	int num, ret;

	fprintf(stdout, "A number between 0-8192 :>");
	do
	{
		ret=scanf("%d", &num);
	}while(getchar() != '\n');

	// wrong input
	if(ret == 0)
	{
		errorfu(EXIT, error[0]);
		return EXIT_FAILURE;
	}
	// overflow
	else if(num > MAX)
	{
		errorfu(WARN, error[1]);
		return EXIT_FAILURE;
	}
	// negative number
	else if(num < 0)
	{
		errorfu(ERROR, error[2]);
		return EXIT_FAILURE;
	}
	// all right
	else
		errorfu(MISC, "Input is O.K.\n");
	return EXIT_SUCCESS;
}

int ex54(void)
{
	return errorf();
}
