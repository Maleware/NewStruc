#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memmovef(void)
{
	char str[21] = "1234567890";

	// take complete string and copy 10 bytes
	memmove(str+10, str, sizeof(str)-1);
	fprintf(stdout, "%s\n", str);
	return EXIT_SUCCESS;
}

int ex616(void)
{
	return memmovef();
}
