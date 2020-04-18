#include <stdlib.h>
#include <stdio.h>

#define errprintf(...) fprintf(stderr, __VA_ARGS__)

int variadic(void)
{
	const char str[] = "a Argument";
	int val = 10;

	errprintf("Hello world %d %s\n", val, str);
	errprintf("Error!! Line: %d (%s)\n", __LINE__, __DATE__);
	return EXIT_SUCCESS;
}

int ex55(void)
{
	return variadic();
}
