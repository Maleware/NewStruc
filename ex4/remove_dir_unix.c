#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int removedirunix(void)
{
	char pathname[255];
	char deletefiles[255];

	fprintf(stdout, "Which directory should be deleted? :> ");
	do
	{
		scanf("%254s", pathname);
	}while(getchar() != '\n');

	strcpy(deletefiles, "rm -r ");
	strcat(deletefiles, pathname);
	strcat(deletefiles, "/*");
	
	fprintf(stdout, "%s \n", deletefiles);
	system(deletefiles);
	if(rmdir(pathname) == -1)
	{
		fprintf(stderr, "Unable to delte %s directory..\n", pathname);
		fprintf(stderr, "--> %s \n", strerror(errno));
	}
	return EXIT_SUCCESS;
}

int ex44(void)
{
	return removedirunix();
}
