#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifdef __unix__
	#include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
	#include <io.h>
#endif

int close1(void)
{
	int fh;

	if( (fh=open("adressen.txt", O_RDONLY | O_CREAT)) == -1  )
	{
		perror("Error with open()");
		return EXIT_FAILURE;
	}
	if( (close(fh)) == -1)
		printf("While closing a error occured\n");
	return EXIT_SUCCESS;
}

int ex320(void)
{
	return close1();
}
