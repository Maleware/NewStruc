#include <stdio.h>
#include <stdlib.h>

void bubblef(int *array, int elements)
{
	int i, temp;

	while(elements--)
		for(i=1;i<=elements;i++)
			if(array[i-1]>array[i])
			{
				temp=array[i];
				array[i]=array[i-1];
				array[i-1]=temp;
			}
}

int bubble(void)
{
	int i;

	int test_array[]={5,2,7,9,1,4,3,8,6};
	int N=sizeof(test_array)/sizeof(int);

	bubblef(test_array, N);

	for(i=0; i<N; i++)
		fprintf(stdout, "%d", test_array[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

int ex82(void)
{
	return bubble();
}
