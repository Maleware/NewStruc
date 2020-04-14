#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
	#include<unistd.h>
#else
	#include<io.h>
#endif

int filenof(void)
{
	FILE *fz;
	int fd, fd2;
	char file[255];

	printf("File descriptor to stdin, stdout and stderr: ");
	printf("%d, %d and %d \n", fileno(stdin), fileno(stdout), fileno(stderr));
	printf("Which file to open? >");
	do
	{
		scanf("%s", file);
	}while(getchar() != '\n');

	fz=fopen(file, "r");
	if(!fz)
	{
		perror(NULL);
		return EXIT_FAILURE;
	}
	fd = fileno(fz);
	printf("File descriptor to file %s is %d \n", file, fd);
	fd2=dup(fd);
	printf("Copied file descriptor is %d \n", fd2);
	return EXIT_SUCCESS;
}

int ex323(void)
{
	return filenof();
}
