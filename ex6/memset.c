#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memsetf(void)
{
	char credit_card[21] = "123456-aiex";
	char *ptr = strchr(credit_card, '-');

	*ptr++;
	// don't show last 4 digets of number
	memset(ptr, '*', 4);
	fprintf(stdout, "%s\n", credit_card);
	return EXIT_SUCCESS;
}

int ex617(void)
{
	return memsetf();
}
