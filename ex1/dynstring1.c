#include "../output.h"
#include "../input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 255

int dyn_string1(void)
{
	size_t len;
	char *str = NULL;
	char puffer[BUF];

	printout("A dynamic char-array for strings");
	printout("Type in: ");
	fgets(puffer, BUF, stdin);
	str = malloc(strlen(puffer)+1);
	if(NULL==str)
	{
		printout("no virtuell RAM available");
		return EXIT_FAILURE;
	}
	
	strcpy(str, puffer);
	printout("More input or exit with \"END\"\n>");
	// Endless loop
	while(1)
	{
		fgets(puffer, BUF, stdin);
		// Break condition
		if (strcmp(puffer,"end\n")==0 || strcmp(puffer, "END\n")==0)
				break;
		// Count str length
		len = strlen(str);
		// get storage for str
		str = realloc(str,strlen(puffer)+len+1);
		if(NULL==str)
		{
		printout("no virtuell RAM available");
		return EXIT_FAILURE;
		}
		// connect string behind original one
		strcat(str, puffer);

	}
	printout("Input was: ");
	printf("%s", str);
	free(str);
	return EXIT_SUCCESS;

}

int ex11(void)
{
	dyn_string1();
	return 0;
}
