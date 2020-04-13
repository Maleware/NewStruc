#include <stdio.h>
#include <stdlib.h>

struct
{
	char fname[20];
	char lname[20];
	char road[20];
	char number[20];
	char zip[7];
	char place[20];
	char starsign[30];
	char age[3];
}adresses;

void savef(void)
{
	FILE *save=fopen("adresses.dat","r+");
	if(NULL==save)
	{
		save=fopen("adresses.dat","w+");
		if(NULL==save)
		{
			fprintf(stderr, "Unable to open \" adresses.dat \" \n");
			return;
		}
	}
	// File pointer to end of adresses.dat
	fseek(save, 0, SEEK_END);

	// Write on the End of adresses.dat
	if(fwrite(&adresses, sizeof(adresses),1,save) != 1)
	{
		fprintf(stderr, "Error with fwrite()....\n");
		return;
	}
	// release file pointer
	fclose(save);
}

void output314(void)
{
	FILE *output = fopen("adresses.dat", "r+");
	if(NULL==output)
	{
		fprintf(stderr, "Unable to open \" adresses.dat \" \n");
		return;
	}
	// read all adresses from adresses.dat
	while(fread(&adresses, sizeof(adresses), 1, output)==1)
	{
		printf("First name.......: %s", adresses.fname);
		printf("Last name........: %s", adresses.lname);
		printf("Road.............: %s", adresses.road);
		printf("Number...........: %s", adresses.number);
		printf("Zip code.........: %s", adresses.zip);
		printf("Place............: %s", adresses.place);
		printf("Star sign........: %s", adresses.starsign);
		printf("Age..............: %s", adresses.age);
		printf("\n\n");
	}
	fclose(output);
}

void input314(void)
{
	printf("Fist name.........:");
	fgets(adresses.fname, sizeof(adresses.fname),stdin);
	printf("Last name.........:");
	fgets(adresses.lname, sizeof(adresses.lname),stdin);
	printf("Road..............:");
	fgets(adresses.road, sizeof(adresses.road),stdin);
	printf("Number............:");
	fgets(adresses.number, sizeof(adresses.number),stdin);
	printf("Zip code..........:");
	fgets(adresses.zip, sizeof(adresses.zip),stdin);
	printf("Place.............:");
	fgets(adresses.place, sizeof(adresses.place),stdin);
	printf("Star sign.........:");
	fgets(adresses.starsign, sizeof(adresses.starsign),stdin);
	printf("Age...............:");
	fgets(adresses.age, sizeof(adresses.age),stdin);
	savef();
}

int freadfwrite(void)
{
	int choice;
	do
	{
		printf("What to do? \n\n");
		printf("-1- Insert new adress\n");
		printf("-2- Print all adresses\n");
		printf("-3- End Programm\n");
		printf("Your selection: > ");
		do
		{
			scanf("%d",&choice);
		}while( getchar() != '\n' );
		switch(choice)
		{
			case 1: input314();
				break;
			case 2: output314();
				break;
			case 3: printf("... Programm ended\n");
				break;
			default: printf(">>%d<< ... \n", choice);
		}
	}while(choice != 3);
	return EXIT_SUCCESS;
}

int ex314(void)
{
	return freadfwrite();
}
