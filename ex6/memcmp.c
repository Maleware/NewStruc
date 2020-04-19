#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memcmpf(void)
{
	char str1[]="Have a lot of fun";
	char str2[]="Have more than a lot of fun";
	int check, i;

	for(i=4; i<=10; i+=6)
	{
		check=memcmp(str1,str2,i);
		if(check==0)
			fprintf(stdout, "In %d bytes, strings are equal \n", i);
		else
			fprintf(stdout, "The first %d bytes are differnt \n", i);
	}
	return EXIT_SUCCESS;
}

int ex614(void)
{
	return memcmpf();
}
