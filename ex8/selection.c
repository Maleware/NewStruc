#include <stdio.h>
#include <stdlib.h>

void selectionf(int *array, int element)
{
	int index, index_small, value, value_small;

	// Loop runs from left to right
	for(index = 0; index < element; index++)
	{
		// actual position
		value=index;
		// Loop runs through programm, looking for the
		// next smaller element than the one on 
		// actual position or till end and therefore
		// actual element is smallest
		for(index_small = index+1; index_small <= element; index_small++)
		{
			if(array[index_small] < array[value]) // found smaller element?
				value=index_small; // new smallest element
		}
		// smallest element to first position if neccessarry
		if(value != index)
		{
			value_small=array[value];
			array[value]=array[index];
			array[index]=value_small;
		}
	}
}

int selection(void)
{
	int i;
	 // Test Array to sort
	 int test_array[]={5,2,7,9,1,4,3,8,6};
	 int N = sizeof(test_array)/sizeof(int);

	 selectionf(test_array, N-1);
	 for(i=0; i<N; i++)
		 fprintf(stdout, "%d",test_array[i]);
	 fprintf(stdout, "\n");
	 return EXIT_SUCCESS;
}

int ex80(void)
{
	return selection();
}
