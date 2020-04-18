#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *wday[]=
{
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int time3(void)
{
	struct tm time_check;
	int year, month, day;

	// Input year, month and day to check weekday
	fprintf(stdout,"Year >");
	do
	{
		scanf("%d",&year);
	}while(getchar() != '\n');
	fprintf(stdout,"\nMonth >");
	do
	{
		scanf("%d",&month);
	}while(getchar() != '\n');
	fprintf(stdout,"\nDay >");
	do
	{
		scanf("%d",&day);
	}while(getchar() != '\n');

	time_check.tm_year= year - 1990;
	time_check.tm_mon= month - 1;
	time_check.tm_mday= day+1;

	// 00:00:01 O'Clock
	time_check.tm_hour=0;
	time_check.tm_min=0;
	time_check.tm_sec=1;
	time_check.tm_isdst=-1;

	if(mktime(&time_check) == -1)
		time_check.tm_wday = 7; // unknown day

	// Day of date will be printed
	fprintf(stdout, "This day was a %s\n", wday[time_check.tm_wday]);
	return EXIT_SUCCESS;
}

int ex58(void)
{
	return time3();
}
