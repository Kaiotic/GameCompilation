#include "Utility.h"
#include <conio.h>
#include <Windows.h>

/*****************************************************************************
void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg)
	Description :
		Gets input from the user.
	Parameters : 
		const char* _sFormat: The format of the input. (e.g. "%s")
		void* _vInput: The variable to write the input to.
		const char* _sInputMsg: The message to prompt the user input.
		const char* _sError: The error message to display on invalid input.
	Returns : -
*****************************************************************************/
void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg, const char* _sError)
{
	int iErr = 1;

	do
	{
		if(iErr != 1)
		{
			printf("%s", _sError);
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
	while((cChar = _getch()) != '\r' && iCount <= 19)
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
				// move 1 character left, print space, move 1 character left again
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

/*****************************************************************************
int initGameBoard(Field_t* _Board, size_t _iRow, size_t _iCol)
	Description :
		Initializes the GameBoard.
	Parameters : 
		Field_t* _Board: The board to initialize.
		Vec2df32_t _Offset: The positional offset of the board.
		size_t _iRow: The number of rows.
		size_t _iCol: The number of columns.
	Returns :
		int: TRUE if everything went well, FALSE if not.
*****************************************************************************/
int initGameBoard(Field_t* _Board, Vec2df32_t _Offset, size_t _iRows, size_t _iCols)
{
	// rows and columns
	size_t i = 0; 
	size_t j = 0; 

	// remember first element
	Field_t* ptrFirst = _Board;

	for(i = 0; i < _iRows; ++i)
	{
		for(j = 0; j < _iCols; ++j)
		{
			// initialize board with offset
			_Board->Position.iX = (float)(i + 5) * _Offset.iX;
			_Board->Position.iY = (float)j * _Offset.iY;
			_Board->Value = 'x';

			// move pointer
			++_Board;
		}
	}

	// reset pointer to first element
	_Board = ptrFirst;

	// everything went well
	return TRUE;
}

/*****************************************************************************
void cleanUpGameBoard(Field_t* _Board)
	Description :
		Frees resources.
	Parameters : 
		Field_t* _Board: The board to clean up.
	Returns : -
*****************************************************************************/
void cleanUpGameBoard(Field_t* _Board)
{
	if(_Board)
	{
		free(_Board);
		_Board = NULL;
	}
}

