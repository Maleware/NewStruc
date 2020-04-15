#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef __linux__
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#define MODUS ,0711
#elif __WIN32__ || _MS_DOS_
	#include <dir.h>
	#define MODUS )
#else
	#include <direct.h> //Visual C++
	#define MODUS )
#endif

int changedir(void)
{
	char pathname[255];

	fprintf(stdout, "Name of new folder: >");
	//fgets(pathname, 255, stdin); only useable if one cutout the end
	
	do
	{
		scanf("%s", pathname);
	}while(getchar() != '\n');

	if(mkdir(pathname MODUS) == -1)
		fprintf(stderr, "Unable to create new directory..\n");
	else
	{
		fprintf(stdout, "Created new directory named: %s", pathname);
		fprintf(stdout, "--> %s \n", strerror(errno));
	}

	// now change into new directory
	if( chdir(pathname) == -1)
	{
		fprintf(stderr, "Unable to change directory..\n");
		return EXIT_FAILURE;
	}
	else
		fprintf(stdout, "Successfuly changed to %s \n", pathname);
	fopen("testfile", "w+");
	return EXIT_SUCCESS;
}

int ex42(void)
{
	return changedir();
}
