#include "Utility.h"
#include "stdheader.h"

/*****************************************************************************
void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg)
Description :
Gets input from the user.
Parameters : 
const char* _sFormat: The format of the input. (e.g. "%s")
void* _vInput: The variable to write the input to.
const char* _sInputMsg: The message to prompt the user input.
Returns : -
*****************************************************************************/
void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg)
{
	int iErr = 1;

	do
	{
		if(iErr != 1)
		{
			printf("Error. Please try again.");
		}

		printf("\n%s", _sInputMsg);

		fflush(stdin);
	}
	while((iErr = scanf(_sFormat, _vInput)) != 1);
}
