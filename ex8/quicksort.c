#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int test_array[MAX];

void my_qsort(int *, int *);

void init_test_arrayq(void)
{
	int i, j;
	for(i=MAX,j=0; i>=0; i--,j++)
		test_array[j]=i;
}

void print_test_array(void)
{
	int i;
	for(i=0; i<MAX; i++)
		fprintf(stdout, "%d ", test_array[i]);
}

// Function gets a pointer to first and a second pointer to the
// last element. To show this we name them "left" and "right"

void my_qsort(int *left, int *right)
{
	int *ptr1 = left;
	int *ptr2 = right;

	int w, x;

	// x get's the starting adress from the middle of left and right
	
	x = *(left + ((right - left) >> 1));
	do
	{
		while(*ptr1 < x) 
			ptr1++;
		while(*ptr2 > x)
			ptr2--;
		if(ptr1 > ptr2)
			break;
		w=*ptr1;
		*ptr1= *ptr2;
		*ptr2= w;
	}while(++ptr1 <= --ptr2);
	if(left < ptr2)
		my_qsort(left, ptr2);
	if(ptr1 < right)
		my_qsort(ptr1, right);
}

int my_qsortm(void)
{
	int t1, t2;
	init_test_arrayq();
	t1=clock();
	my_qsort(test_array, test_array+MAX);
	t2=clock();
	fprintf(stdout, "Runtime messurement showed %2.2f\n", 
			(float)(t2-t1)/(float)CLOCKS_PER_SEC);
	print_test_array();
	return EXIT_SUCCESS;
}

int ex85(void)
{
	return my_qsortm();
}
