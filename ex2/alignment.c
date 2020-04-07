#include <stdio.h>
#include <stdlib.h>

struct memory
{
	char x;
	int z;
};

void original(void)
{
	struct memory test;

	printf("%lu bytes used \n",sizeof(test));
}

struct memoryc
{
	char x;
	int z;
}__attribute__((packed));

void compact(void)
{
	struct memoryc test1;
	
	printf("%lu bytes used compressed \n",sizeof(test1));
}

enum{TRUE, FALSE}__attribute__((packed));

void enum1(void)
{
	printf("%lu bytes used for enum \n",sizeof(TRUE));
}

int ex211(void)
{
	original();
	compact();
	enum1();
	return EXIT_SUCCESS;
}
