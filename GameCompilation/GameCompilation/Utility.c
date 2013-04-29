#include "Utility.h"
#include "stdheader.h"

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