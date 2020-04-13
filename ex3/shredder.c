#include <stdio.h>
#include <stdlib.h>

void shredder(char *rm)
{
	unsigned long size;

	FILE *rem=fopen(rm,"w+");
	if(rem != NULL)
	{
		fseek(rem, 0L, SEEK_END); // End of File
		size=ftell(rem); // Size in Bytes
		// override file with \0
		fwrite( (char *)'\0', 1, size, rem );
		// to delete close first
		fclose(rem);
		remove(rm);
	}
}

int remove1(void)
{
	char file[]="testdata/test.txt";
	shredder(file);
	return EXIT_SUCCESS;
}

int ex316(void)
{
	return remove1();
}
