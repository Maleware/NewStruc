#include <stdio.h>
#include <stdlib.h>

void insertionf(int *array, int elements)
{
	int index, index_small, value_small;

	// Loop from left to right
	for(index=1; index<=elements; index++)
	{
		// temp save poistion
		value_small=array[index];
		// search for smaller value then value_small.
		// Loop goes from right to left, starting from
		// actual position
		for(index_small = index;
		    array[index_small-1] > value_small && index_small > 0;
		    index_small --)
			// if previous element is taler than actuel element
			// in value_small
			array[index_small]=array[index_small - 1];
		// saved element to new position -> fill gap
		array[index_small]=value_small;
	}
}

int insertion(void)
{
	int i;
	int test_array[]={5,2,7,9,1,4,3,8,6};
	int N=sizeof(test_array)/sizeof(int);

	insertionf(test_array, N-1);

	for(i=0; i<N; i++)
		fprintf(stdout, "%d", test_array[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

int ex81(void)
{
	return insertion();
}
