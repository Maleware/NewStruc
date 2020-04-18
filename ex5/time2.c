#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm *tmnow;

void today(void)
{
	time_t tnow;

	time(&tnow);
	tmnow = localtime(&tnow);
	fprintf(stdout,"Today it's the ");
	fprintf(stdout,"%d.%d.%d\n", tmnow->tm_mday, tmnow->tm_mon+1, tmnow->tm_year+1900);
}

int time2(void)
{
	int day, month, year;
	unsigned int i=0, tmp;

	fprintf(stdout, "Insert your Birthday: \n");
	fprintf(stdout, "Day >");
	do
	{
		scanf("%d",&day);
	}while(getchar() != '\n');
	fprintf(stdout, "\nMonth >");
	do
	{
		scanf("%d",&month);
	}while(getchar() != '\n');
	fprintf(stdout, "\nYear >");
	do
	{
		scanf("%d",&year);
	}while(getchar() != '\n');

	today();

	if(tmnow->tm_mon < month)
	{
		i=1;
		tmp=tmnow->tm_mon+1-month;
		month=tmp+12;
	}
	else
	{
		tmp=tmnow->tm_mon+1-month;
		month=tmp;
	}
	if(month == 12)
	{
		month=0;
		i=0;
	}

	fprintf(stdout, "Your age is: %d Years %d Month %d Days \n",
			tmnow->tm_year+1900-year-i, month, tmnow->tm_mday-day);
	return EXIT_SUCCESS;
}

int ex57(void)
{
	return time2();
}
