#include <stdio.h>
#include <stdlib.h>

int char4char(void)
{
	FILE *source, *target;
	int c;
	char name_s[255], name_t[255];

	printf("Name of the source: >");
	scanf("%s", name_s);
	source=fopen(name_s,"r");

	if(source == NULL)
	{
		printf("Unable to open %s\n", name_s);
		return EXIT_FAILURE;
	}	
	else
	{
		printf("Name of the source data: >");
		scanf("%s", name_t);
		target=fopen(name_t,"w+");
		if(target == NULL)
		{
			printf("Unable to write target \n");
			return EXIT_FAILURE;
		}
		else
		{
			// copy char wise from source to target
			while( (c=getc(source)) != EOF)
			{
				putc(c, target);
			}
			fclose(source);
		}
	}
	fclose(target);
	return EXIT_SUCCESS;
}

int ex34(void)
{
	
	return char4char();
}
