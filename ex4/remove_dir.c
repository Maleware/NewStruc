#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef __linux__
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#define MODUS ,0711)
#elif __WIN32__ || _MS_DOS_
	#include <dir.h>
	#define MODUS )
#else
	#include <direct.h> //Visual C++
	#define MODUS )
#endif

int makedir(char *dir)
{
	if(mkdir(dir MODUS != -1)
		if(chdir(dir) != -1)
			return 0;
	return -1;	
}

int removedir(void)
{
	char pathname[255];

	fprintf(stdout, "Name of the new folder: >");

	do
	{
		scanf("%254s", pathname);
	}while(getchar() != '\n');
	
	if(makedir(pathname) == -1)
	{	
		fprintf(stderr, "Unable to create new directory..\n");
		fprintf(stderr, "--> %s \n", strerror(errno));
	}
	// create testfile in directory
	fopen("testfile", "w+");

	if(rmdir(pathname) == -1)
	{
		fprintf(stderr, "Unable to delete %s \n", pathname);
		fprintf(stderr, "--> %s \n", strerror(errno));
	}
	return EXIT_SUCCESS;
}

int ex43(void)
{
	return removedir();
}
