#include <stdio.h>
#include <stdlib.h>

void char4char(void)
{
	FILE *source, *target;
	int c;
	char name_s[255], name_t[255];

	printf("Name of the source: >");
	scanf("%s", name_s);
	fflush(stdin);
	source=fopen(name_s,"r");

	if(source == NULL)
	{
		printf("Unable to open %s\n", name_s);
	}
	else
	{
		printf("Name of the source data: >");
		scanf("%s", name_t);
		fflush(stdin);
		target=fopen(name_t,"w+");
		if(target == NULL)
		{
			printf("Unable to write target \n");
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
}

int ex34(void)
{
	char4char();
	return 0;
}
