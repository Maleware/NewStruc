#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memchrf(void)
{
	char str1[]="Have a lot of fun";
	char *p;
	char ch = '1';

	p= (char *) memchr(str1, ch, 10);
	if(NULL == p)
		fprintf(stderr, "%c not mentioned in the first 10 bytes\n", ch);
	else
		fprintf(stdout, "%c found at Pos %ld", ch, p-str1);
	return EXIT_SUCCESS;
}

int ex613(void)
{
	return memchrf();
}
