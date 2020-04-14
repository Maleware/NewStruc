#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifdef __unix__
	#include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
	#include <io.h>
#endif

int write1(void)
{
	int fh;
	char buffer[100];

	strcpy(buffer, "This is written in \"testdata/test.txt\"\n");

	if( (fh=open("testdata/test.txt", O_RDWR |O_CREAT|O_TRUNC) ) == -1)
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	if( (write(fh, &buffer, sizeof(buffer))) == -1)
	{
		perror("Feher with write()");
		return EXIT_FAILURE;
	}
	printf("Written succesfully in \"testdata/test.txt\"");
	return EXIT_SUCCESS;

}

int ex321(void)
{
	return write1();
}
