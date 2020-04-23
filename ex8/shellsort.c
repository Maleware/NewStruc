#include <stdio.h>
#include <stdlib.h>

void shellsortf(int *array, int elements)
{
	int i, j, temp, n;

	// Calculate starting value for the distance
	for(n=1; n<=elements/9; n=3*n+1);
	for(; n>0; n /= 3)
	{
		for(i=n; i<=elements; i++)
		{
			temp=array[i];
			// taller than temp and not element 
			// as well as >= and not >
			for(j=i;
			    j >= n && array[j-n] > temp;
			    j -= n)
			{
				array[j] = array[j-n];
			}
			array[j] = temp;
		}
	}
}

int shellsort(void)
{
	int i;
	
	int test_array[]={5,0,2,7,9,1,4,3,8,6};
	int N= sizeof(test_array)/sizeof(int);

	shellsortf(test_array, N-1);

	for(i=0; i<N; i++)
		fprintf(stdout, "%d", test_array[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

int ex83(void)
{
	return shellsort();
}
