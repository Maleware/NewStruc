#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#else
	#include <sys\stat.h>
#endif

int filecheck(int count, char *path)
{
	struct stat attribut;
	
	if(count == 1)
	{
		printf(" %s = ", path);
		if( stat(path, &attribut) == -1)
		{
			fprintf(stderr, "Error with stat....\n");
			return EXIT_FAILURE;
		}
		if(attribut.st_mode && S_IFREG)
			printf("It's a regular file \n");
		if(attribut.st_mode && S_IFDIR)
			printf("It's a directory \n");
		if(attribut.st_mode && S_IFCHR)
			printf("It's a device dependent file \n");
		else
			printf("Unknown file..\n");
	}
	else
	{
		while(1)
		{
			printf(" %s = ", path);
	
			if( stat(path, &attribut) == -1)
			{
				fprintf(stderr, "Error with stat (2)....\n");
				return EXIT_FAILURE;
			}
			if(attribut.st_mode && S_IFREG)
				printf("It's a regular file \n");
			if(attribut.st_mode && S_IFDIR)
				printf("It's a directory \n");
			if(attribut.st_mode && S_IFCHR)
				printf("It's a device dependent file \n");
			else
				printf("Unknown file..\n");
			break;		
		}
	}
	return EXIT_SUCCESS;
}

int ex40(void)
{
	int count;
	char path[255];
	printf("Which file to check? > ");
	do
	{
		scanf("%s",path);
	}while(getchar() != '\n');
	count=strlen(path);
	return filecheck(count, path);
}
