#include "../output.h"
#include "../input.h"
#include <stdio.h>
#include <stdlib.h>

void realloc1(void)
{
	int n=0, max=10, z=0,i=0;
	int *numbers=NULL;

	// Reserving stoarge for 10 int-Values
	numbers = calloc(max, sizeof(int));
	if(NULL == numbers)
	{
	printout("No virtuell RAM available");
	return EXIT_FAILURE;
	}
	printout("Type in Numbers ---- Stop with 0");
	// Infinity Loop
	while(1)
	{
		printf("Type Number (%d): ",n+1);
		scanf("%d",&z);
		if(z==0)
			break;
		// Reserving space during runtime with realloc()
		if(n>=max)
		{
			max += max;
			numbers = realloc(numbers, max*sizeof(int));
			if (NULL == numbers)
			{
				printout("No virtuell RAM available");
				return EXIT_FAILURE;
			}
			printf("Storrage allocated for (%ld Bytes)",sizeof(int)*max);
		}
		numbers[n++] = z;
	}
	printf("Following numbers where typed in -> \n\n");
	for(i=0;i<n;i++)
		printf("%d ", numbers[i]);
	printout("\n");
	free(numbers);
}

int ex10(void)
{
	realloc1();
	return 0;
}
