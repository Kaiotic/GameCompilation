#include "Utility.h"
#include "stdheader.h"
#include <string.h>
#include <conio.h>

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
	// loop until valid input is entered
	while((iErr = scanf(_sFormat, _vInput)) != 1);
}

/*****************************************************************************
char* getMaskedPassword(const char* _sInputMsg)
Description :
	Gets the password from the user.
Parameters : 
	const char* _sInputMsg: The message to prompt the user input.
Returns :
	char*: The entered password.
*****************************************************************************/
char* getMaskedPassword(const char* _sInputMsg)
{
	// sPassword can be 20 characters long
	char* sPassword = (char*)calloc(20, sizeof(sPassword));
	char cChar = '\0';
	int iCount = 0;

	printf("%s", _sInputMsg);

	// loop until Enter is pressed or 19 (+ "\0") characters have been entered
	while((cChar = _getch()) != '\r' || iCount >= 19)
	{
		// if cChar is not Backspace
		if(cChar != '\b')
		{
			printf("*");
			sPassword[iCount] = cChar;
			++iCount;			
		}
		else
		{
			if(iCount > 0)
			{
				// remove last character from console
				printf("\b \b");

				// terminate string after last character
				sPassword[iCount] = '\0';
				--iCount;
			}
		}
	}
	printf("\n");

	// terminate string
	sPassword[++iCount] = '\0';

	return sPassword;
}