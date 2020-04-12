#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *CSV;
	int login_hour, login_min;
	int date_day, date_mon, date_year;
	char name[40];
	int logout_hour, logout_min;
	int date_dayx, date_monx, date_yearx;

	if(argc < 2)
	{
		fprintf(stderr, "Usage : %s file.csv\n", *argv);
		return EXIT_FAILURE;
	}
	CSV=fopen(argv[1], "r");

	if(NULL == CSV)
	{
		fprintf(stderr, "Unable to open file....\n");
		return EXIT_FAILURE;
	}

	// read and formate data
	while((fscanf(CSV,"%d:%d,%d.%d.%d,%d:%d, %d.%d.%d, %s\n",
		&login_hour, &login_min,&date_day,&date_mon,&date_year,
		&logout_hour, &logout_min, &date_dayx,&date_monx,
		&date_yearx,name)) != EOF)
		fprintf(stdout,"User:%s\nLogin at: %d:%d on %d.%d.%d\n"
			"Logut at: %d:%d on %d.%d.%d\n\n ",
			name, login_hour, login_min, date_day, date_mon, date_year,
			logout_hour, logout_min, date_dayx, date_monx, date_yearx);
	return EXIT_SUCCESS;
}

int ex35(void)
{
	int r;
	//char *fpath;
	//printf("Insert path of csv-file: > ");
	//scanf("%c", fpath);
	//c=strlen(fpath);
	r=main();
	return r;
	
}
