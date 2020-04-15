#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static void myprintf(char *string, ...)
{
	va_list argptr;
	va_start(argptr,string);
	vprintf(string,argptr);
	va_end(argptr);
}

int my_printf(void)
{
	char hello[]="Hello vprintf\n";
	myprintf("A example of vprintf");
	myprintf("\n");
	myprintf("%d * %d = %d\n", 10,10,10*10);
	myprintf("%s", hello);
	return EXIT_SUCCESS;
}

int ex53(void)
{
	return my_printf();
}
