#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
	#include <sys/types.h>
	#include <sys/stat.h>
	#define MODUS ,0711
#elif __WIN32__ || _MS_DOS_
	#include <dir.h>
	#define MODUS )
#else
	#include <direct.h> //Visual C++
	#define MODUS )
#endif


int createdir(void)
{
	char pathname[255];

	printf("Path to new folder (../foldername): > ");
	do
	{
		scanf("%s",pathname);
	}while(getchar() != '\n');

	if( mkdir(pathname MODUS == -1) )
		fprintf(stderr, "Couldn't create new directory...\n");
	else
		fprintf(stdout, "Directory %s created \n", pathname);
	return EXIT_SUCCESS;
}

int ex41(void)
{
	return createdir();
}
