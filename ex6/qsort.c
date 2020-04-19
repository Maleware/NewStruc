#include <stdio.h>
#include <stdlib.h>

//comparsion function
int cmpq(const void *ptr1, const void *ptr2)
{
	if(*(int *)ptr1 < *(int *)ptr2 )
		return -1;
	else if(*(int *)ptr1 > *(int *)ptr2)
		return 1;
	else
		return 0; // elements are equal
}

int qsortf(void)
{
	int value[] = { 2, 5, 2, 7, 6, 4, 2};
	int i;

	fprintf(stdout, "Data bevor sorting\n");
	for(i=0; i<sizeof(value)/sizeof(int); i++)
		fprintf(stdout, "%d \t", value[i]);
	fprintf(stdout, "\n");

	// sorting via qsort
	qsort(value, sizeof(value)/sizeof(int), sizeof(int), cmpq);

	fprintf(stdout, "Data after sorting with qsort\n");
	for(i=0; i < sizeof(value)/sizeof(int); i++)
		fprintf(stdout, "%d\t", value[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

int ex68(void)
{
	return qsortf();
}
