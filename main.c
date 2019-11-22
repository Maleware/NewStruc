#include "main.h"
#include "output.h"
#include "input.h"

//TODO Put Input functions in an own file

//TODO Not very readable
int main(void)
{
	char input[IN_SZ];
	int retv = 0;
	while(1)
	{
		II_Action action = None;
		unsigned int insz = 0;
		int rires = 0;
		printout("Enter action: ");
		rires = readInput(input, IN_SZ, &insz);
		if (rires == RI_EOF)
			break;
	
		if (rires == RI_INSUFFICIENT_BUFFER_SIZE)
			printerr("Insufficient buffer size ignoring remaining characters");
		else if (rires)
		{
			printerr("Error reading input");
			break;
		}
		if (insz > IN_SZ)
		{
			printerr("Unknwon error reading input");
			retv = 1;
			break;
		}
		if(interpretInput(input, insz, &action))
			printerr("Could not interpret input");
		else
		{
			rires = executeInput(action, input, insz);
			if (rires == EI_EXIT)
				break;
			//TODO Make pretty after separating retvs
			//TODO Put strings somewhere else
			if (rires != EXAMPLE_SUCCESS)
			{
				switch(rires)
				{
				case EXAMPLE_FAIL:
					printerr("Example failed");
					break;	
				case EI_EX_DETER_FAILED:
					printerr("Example number could not be determined");
				      	break;
				case EE_UNKNOWN_EXNO:
					printerr("Example number not found");
					break;
				case EI_UNKNOWN_ACTION:
					printerr("Unrecognised action");
					break;
				default:
					printerr("Unknwon error while trying to execute input");
				}
			}
		}
	}
	return retv;
}
