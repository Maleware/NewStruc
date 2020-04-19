#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void func1(int);
void func2(int);
void func3(int);
void func4(void);
jmp_buf env;

static int num;

void func1(int numb)
{
	fprintf(stdout, "Function 1 is called...\n");
        if(numb == 1)
		longjmp(env, 1);
	func2(num);	
}

void func2(int numb)
{
	fprintf(stdout, "Function 2 is called...\n");
	if(numb == 2)
		longjmp(env, 2);
	func3(num);
}

void func3(int numb)
{
	fprintf(stdout, "Function 3 is called...\n");
	if(numb == 3)
		longjmp(env, 3);
	func4();
}

void func4(void)
{
	fprintf(stdout, "Function 4 is called...\n");
}

int setjmpf(void)
{
	fprintf(stdout, "Number of function you want to call :>");
	do
	{
		scanf("%d", &num);
	}while(getchar() != '\n');
	if(setjmp(env) == 0)
		func1(num);
	else
		fprintf(stdout, "Jumping back with lonjmp from function %d \n", num);
	return EXIT_SUCCESS;
}

int ex610(void)
{
	return setjmpf();
}
