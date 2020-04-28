#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __unix__
	#define clrscr() fprintf(stdout, "\x1b[2J")
#elif __BORLANDC__ && __MSDOS__
	#include <conio.h>
#elif __WIN32__ || _MSC_VER
	#define clrscr() system("cls")
#else
	#define clrscr() fprintf(stderr, "clrscr() - Error!!\n")
#endif

#define barrier 100

char playground[15][50];

void createplayground(void)
{
	int i, j, x, y;
	for(i=0, j=0; j<50; j++)
		playground[i][j] = '#';

	for(i=1; i<15; i++)
		for(j=0; j<50; j++)
		{
			if(j==0 || j==49)
				playground[i][j] = '#';
			else
				playground[i][j] = ' ';
			if(i==13 && j==48)
				playground[i][j] = 'O';
		}
	for(i=14, j=0; j<50;j++)
		playground[i][j] = '#';

	for(i=0; i<=barrier; i++)
	{
		x=rand()%14;
		y=rand()%48;
		if(x<15 && y<50 && x>0 && y>0)
			playground[x][y] = '*';
	}
	playground[1][1] = ' ';
}

void showplayground(void)
{
	int i, j;
	clrscr();
	for(i=0; i<15; i++)
		for(j=0; j<50; j++)
		{
			fprintf(stdout, "%c", playground[i][j]);
			if(j==49)
				fprintf(stdout, "\n");
		}
}

int step(int x, int y, int xold, int yold)
{
	fprintf(stdout, "<ENTER>");
	getchar();

	if(playground[x][y] == 'O') //Reached target?
	{
		playground[x][y] = 'C';
		playground[xold][yold] = ' ';
		showplayground();

		fprintf(stdout ,"Mister C made it home...\n");
		exit (EXIT_SUCCESS);
	}
	else if(playground[x][y] == ' ')
	{
		playground[x][y] = 'C';
		playground[xold][yold] = ' ';
		showplayground();
		// move to right
		if(y+1<49 && playground[x][y+1] != '*' &&
		   yold != y+1 && step(x,y+1,x,y) )
			return 1;
		// move down
		if(x+1<14 && playground[x+1][y] != '*' &&
	           xold != x+1 && step(x+1,y,x,y) )
			return 1;
		// move up
		if(x-1>0 && playground[x-1][y] != '*' &&
		   xold != x-1 && step(x-1,y,x,y) )
			return 1;
		// move left
		if(y-1>0 && playground[x][y-1] != '*' &&
		   yold != y-1 && step(x,y-1,x,y) )
			return 1;
	}
	return 0;
}

int mister_c(void)
{
	createplayground();
	step(1,1,1,1);
	return EXIT_SUCCESS;
}

int ex813(void)
{
	return mister_c();
}
