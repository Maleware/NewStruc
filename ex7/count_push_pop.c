#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

#ifdef DEBUG
	int push_cnt=0, pop_cnt=0;
#endif

void push(void)
{
#ifdef DEBUG
	push_cnt ++;
	fprintf(stdout, "Number push: %d\n",push_cnt);
#endif
		// Execute push
}

void pop(void)
{
#ifdef DEBUG
	pop_cnt ++;
	fprintf(stdout, "\t\t Number pop: %d\n", pop_cnt);
	if(pop_cnt > push_cnt)
		fprintf(stderr, "Critical Error: pop_cnt taller push_cnt\n");
#endif
	// Execute pop
}

int cntpushpop(void)
{
	push();
	push();
	pop();
	push();
	pop();
	pop();
	pop(); // Error
	return EXIT_SUCCESS;
}

int ex71(void)
{
	return cntpushpop();
}
