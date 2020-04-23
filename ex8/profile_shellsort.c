#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000
#define MAX_TEST 10

// The array we want to sort
int test_array[MAX];

void init_test_array(void)
{
	int i,j;
	for(i=MAX, j=0; i>=0; i--,j++)
		test_array[j]=i;
}

void shellsortf1(int *array, int elements, int distance)
{
	int i, j, temp, n=elements;
	
	for(; n>0; n/=distance)
		for(i=n; i<=elements; i++)
		{
			temp=array[i];

			for(j=i;
			    j >= n && array[j-n] > temp;
			    j -= n)
			{
				array[j] = array [j-n];
			}
			array[j] = temp;
		}
}

void insertionf1(int *array, int elements)
{
	int index, index_small, value_small;

	for(index=1; index<= elements; index++)
	{
		value_small=array[index];
		for(index_small=index; 
		    array[index_small-1] > value_small && index_small>0; 
		    index_small--)
			array[index_small] = array[index_small-1];
		array[index_small]=value_small;
	}
}


int profile_shellsort(void)
{
	int distance_order;
	float time;
	clock_t start, end;
	int N;

	for(distance_order = 2;
	    distance_order <= MAX_TEST; distance_order++)
	{
		init_test_array();

		start = clock();
		shellsortf1(test_array, MAX-1, distance_order);
		end = clock();

		// Runtime in seconds
		time = (float)(end-start) / (float)CLOCKS_PER_SEC;
		fprintf(stdout, "Runtime messurement for distance " 
				"%d showed %2.2f seconds \n", distance_order, time);
	}
	init_test_array();
	N=sizeof(test_array)/sizeof(int);
	start=clock();
	insertionf1(test_array, N);
	end=clock();

	// Runtime in seconds

	time = (float)(end-start) / (float)CLOCKS_PER_SEC;
	fprintf(stdout, "Runtime messurement for insertion " 
			"showed %2.2f seconds \n", time);
	return EXIT_SUCCESS;
}

int ex84(void)
{
	return profile_shellsort();
}
