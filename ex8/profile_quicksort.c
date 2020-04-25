#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000000

int test_array[MAX];

void my_qsort1(int *, int *);

void init_test_arrayq1(void)
{
	int i, j;
	for(i=MAX, j=0; i>=0; i--,j++)
		test_array[j] = i;
}

//Compare function for qsort()

int cmp_integer(const void *value1, const void *value2)
{
	return(*(int*)value1 - *(int*)value2);
}

void my_qsort1(int *left, int *right)
{
	int *ptr1 = left;
	int *ptr2 = right;
	int w,x;

	x=*(left + ((right - left) >> 1));

	do
	{
		while(*ptr1 < x)
			ptr1++;
		while(*ptr2 > x)
			ptr2--;

		if(ptr1 > ptr2)
			break;
		w = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = w;
	}while(++ptr1 <= --ptr2);
	if(left < ptr2)
		my_qsort1(left, ptr2);
	if(ptr1 < right)
		my_qsort1(ptr1, right);
}

int profile_quicksort(void)
{
	clock_t start, end;

	init_test_arrayq1();
	start=clock();
	qsort(test_array, MAX, sizeof(int), cmp_integer);
	end=clock();
	fprintf(stdout, "qsort() from stdio.h: %.2f\n",
			(float)(end-start) / (float)CLOCKS_PER_SEC);

	init_test_arrayq1();
	start=clock();
	my_qsort1(test_array, test_array+MAX);
	end=clock();
	fprintf(stdout, "selfmade qsort: %.2f\n",
			(float)(end-start) / (float)CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}

int ex86(void)
{
	return profile_quicksort();
}
