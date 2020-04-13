#include <stdio.h>
#include <stdbool.h>
#include "header/input.h"
#include "header/output.h"
#include "header/examples.h"
#include "header/dynarray.h"
#include "header/struc.h"
#include "header/IAfunct.h"

int readInput(char* buf, unsigned int bufsz, unsigned int* outlen)
{
	char c;
	unsigned int pos = 0;
	bool flag = false;
	do
	{
		c = getchar();
		if (c == EOF)
			return RI_EOF;
		if (c == '\n')
			break;
		//Do not 'leak' buffsize (actually totally unecessary)
		if(pos <= bufsz -2)
		{
			buf[pos] = c;
			++pos;	
		}
		//Let the user type as long as he wants (looks more professional)
		else
		{
			flag = true;
		}
	} while(1);
	if (flag || pos > bufsz-1)
	{
		buf[bufsz-1] = '\0';
		*outlen = bufsz;
		return RI_INSUFFICIENT_BUFFER_SIZE;
	}
	//Terminate with 0; otherwise using it as string (someone might do that one day
	//will case problems)
	buf[pos] = '\0';
	*outlen = pos+1;
	return 0;
}


int interpretInput(const char* in, unsigned int insz, II_Action* action)
{
	if (insz < 2)
		return II_NOINTERPRET;
	switch(in[0])
	{
	case 'e':
		*action = Exit;
		return 0;
	case 'h':
		*action = Help;
		return 0;
	case 't': // Trial version for executing example Programms
		*action = ExecuteExample;
		return 0;
	case 'd': // Chapter Dynamic Allocation
		*action = ExecuteDynArray;
		return 0;
	case 's': // Chapter Structure 
		*action = ExecuteStructure;
		return 0;
	case 'i': // Chapter Input/Output function
		*action = ExecuteIAfunct;
		return 0;
	case 'a':
		*action = ExecuteAll;
		return 0;
	}
	return II_NOINTERPRET;
}

int interpretExNo(const char* in, unsigned int insz, int* exampleNo)
{
	unsigned int i = 2;
	if (insz < 4 || in[1] != ' ')
		return II_MALFORMED;
	*exampleNo = 0;
	while(i < insz -1)
	{
		if (in[i] < '0' || in[i] > '9')
			return II_NAN;
		*exampleNo *= 10;
		*exampleNo += in[i]-'0';	
		i++;
		if (in[i] == '\0')
			return 0;
		if (in[i] == ' ')
			return IEN_WHITE_SPACE;

	}
	return IEN_NOINTERPRET;
}

//TODO Allow passing of input
int executeExample(int exNo)
{
	int res = 0;
	printout("\n========");
	indentpush();
	switch(exNo)
	{
	case 0:
		res = ex0();
		break;
	default: res = EE_UNKNOWN_EXNO;
	}
	indentpop();
	printout("========\n");
	return res;
}

int executeDynArray(int exNo)
{
	int res = 0;
	printout("\n========");
	indentpush();
	switch(exNo)
	{
	case 0:
		res=ex10();
		break;
	case 1:
		res=ex11();
		break;
	case 2: 
		res=ex12();
		break;
	case 3:
		res=ex13();
		break;
	case 4:
		res=ex14();
		break;
	default: res = EE_UNKNOWN_EXNO;
	}
	indentpop();
	printout("========\n");
	return res;
}


int executeStructure(int exNo)
{
	int res = 0;
	printout("\n========");
	indentpush();
	switch(exNo)
	{
	case 0:
		res=ex20();
		break;
	case 1:
		res=ex21();
		break;
	case 2:
		res=ex22();
		break;
	case 3:
		res=ex23();
		break;
	case 4:
		res=ex24();
		break;
	case 5:
		res=ex25();
		break;
	case 6:
		res=ex26();
		break;
	case 7:
		res=ex27();
		break;
	case 8:
		res=ex28();
		break;
	case 9:
		res=ex29();
		break;
	case 10:
		res=ex210();
		break;
	case 11:
		res=ex211();
		break;
	default: res = EE_UNKNOWN_EXNO;
	}
	indentpop();
	printout("========\n");
	return res;
}

int executeIAfunct(int exNo)
{
	int res = 0;
	printout("\n========");
	indentpush();
	switch(exNo)
	{
	case 0:
		res=ex30();
		break;
	case 1:
		res=ex31();
		break;
	case 2:
		res=ex32();
		break;
	case 3:
		res=ex33();
		// printf("Not working yet.\n");
		break;
	case 4:
		res=ex34();
		break;
	case 5:
		res=ex35();
		// printf("Not working yet.\n");
		break;
	case 6:
		res=ex36();
		break;
	case 7:
		res=ex37();
		break;
	case 8:
		res=ex38();
		break;
	case 9:
		res=ex39();
		break;
	case 10:
		res=ex310();
		break;
	case 11:
		res=ex311();
		break;
	default: res = EE_UNKNOWN_EXNO;
	}
	indentpop();
	printout("========\n");
	return res;
}

int help(void)
{
	printout("\n *************************************************");
	printout("\n This is the Help-Text for using this Programm ");
	printout("\n Syntax of the Programm is i.e.' t 0 ' for Example first function");
	printout("\n --- You may find some programms implementd, following Rheinwerk Computing C von A bis Z ---");
	printout("\n BASIC's: \n\t (h) Print this helptext \n\t (e) Exit the programm");
	printout("\n (t) Execute Examples not mentioned in the Book \n\t (0) Hello World ");
	printout("\n (d) Execute Examples of Chapter Dynamic Storage management"
		"\n\t (0) Function realloc() with dynamic Storage reservation"
		"\n\t (1) Function dyn_string1 dynamic storage for strings"
		"\n\t (2) Function for dynamic 2 dim array"
		"\n\t (3) Function to change allocated memory"
		"\n\t (4) Splitting required memory");
	printout("\n (s) Exectue programms of Chapter Structure"
		"\n\t (0) First structure of data types "
	      	"\n\t (1) Second structure with print to see"
		"\n\t (2) Structure with pointer and Call-by-Value"
		"\n\t (3) Structure with dynamic allocation and output fct"
		"\n\t (4) Structure comparsion between two structures"
		"\n\t (5) Array of strucutres"
		"\n\t (6) Storage, sort, search and print of max 100 Adresses"
		"\n\t (7) Organisation programm, 100 Adresses, 20 Meetings"
		"\n\t (8) Difference between Struct and Union"
		"\n\t (9) Enum as BOOL listing"
		"\n\t (10) Adresses with typedef"
		"\n\t (11) Comparesion between packed, enum and original space.");
	printout("\n (i) Execute programs of Chapter Input/Output functions."
		"\n\t (0) Open data with fopen "
		"\n\t (1) Putchar funciton "
		"\n\t (2) ECHO function with fgetc echo text to terminal"
		"\n\t (3) Reading data by writing in Terminal or after start"
		"\n\t (4) Copy a file char by char"
		"\n\t (5) Input and formating csv file"
		"\n\t (6) Flag EOF with feof "
		"\n\t (7) ungetc, write last char bevor EOF in file"
		"\n\t (8) Demonstration of fseek()"
		"\n\t (9) right usage of fgets by string comparsion"
		"\n\t (10) Reading the n'th line of file"
		"\n\t (11) Reading from line 1 to line 2 of file");
	printout("\n *************************************************");
	return 0;

}

int executeInput(II_Action action, const char* in, unsigned int insz)
{
	int exNo;
	switch(action)
	{
	case None:
		return 0;
	case Exit:
		return EI_EXIT;
	case Help:
		return help();
	case ExecuteExample:
		if (interpretExNo(in, insz, &exNo) < 0)
			return EI_EX_DETER_FAILED;
		return executeExample(exNo);
	case ExecuteDynArray:
		if (interpretExNo(in, insz, &exNo) < 0)
			return EI_EX_DETER_FAILED;
		return executeDynArray(exNo);

	case ExecuteStructure:
		if (interpretExNo(in, insz, &exNo) < 0)
			return EI_EX_DETER_FAILED;
		return executeStructure(exNo);
	case ExecuteIAfunct:
		if(interpretExNo(in, insz, &exNo) < 0)
			return EI_EX_DETER_FAILED;
		return executeIAfunct(exNo);
	case ExecuteAll:
		//TODO
		return 0;
	}
	return EI_UNKNOWN_ACTION;
}
