#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memcpyf(void)
{
	char str[] = "A word we don't need: Trump";
	char replace[] = "T****";
	char *ptr;

	ptr = strstr(str, "Trump");
	memcpy(ptr, replace, strlen(replace));
	fprintf(stdout, "%s\n", str);
	return EXIT_SUCCESS;
}

int ex615(void)
{
	return memcpyf();
}
