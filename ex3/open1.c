#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifdef __unix__
	#include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
	#include <io.h>
#endif

int open1(void)
{
	int fh;

	if( (fh=open("testdata/adressen.txt", O_RDWR | O_CREAT | O_TRUNC) ) == -1)
	{
		perror("Error with open()");
		return EXIT_FAILURE;
	}
	close(fh);
	return EXIT_SUCCESS;
}

int ex319(void)
{
	return open1();
}
