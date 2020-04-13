#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PASSWORD "Newton"
#define MAX 10

void chomp(char *str)
{
	size_t p=strlen(str);
	// override \n with \0
	str[p-1]='\0';
}

int fgets4(void)
{
	char pswd[MAX];
	while(1)
	{
		printf("Password: >");
		fgets(pswd, MAX, stdin);
		// remove last sign bevore '\0'
		chomp(pswd);

		if(strcmp(PASSWORD, pswd)==0)
		{
			printf("\nWelcome...\n");
			break;
		}	
		else
			printf("\n Wrong password \n");
	}
	return EXIT_SUCCESS;
}

int ex39(void)
{
	return fgets4();
}
