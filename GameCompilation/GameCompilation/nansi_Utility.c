#include "nansi_Utility.h"
#include <Windows.h>

/*****************************************************************************
void printGameBoard(Field_t* _Board, size_t _iSize)
	Description :
		Prints the given board to the console.
	Parameters : 
		Field_t* _Board: The board to print.
		size_t _iSize: The size of the board.
	Returns : -
*****************************************************************************/
void printGameBoard(Field_t* _Board, size_t _iSize)
{
	size_t i = 0;
	COORD pos; // console coordinates
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	system("CLS");

	for(i = 0; i < _iSize; ++i)
	{
		// set coordinates
		pos.X = (short)_Board->Position.iX;
		pos.Y = (short)_Board->Position.iY;

		// move cursor to position
		SetConsoleCursorPosition(hOutput, pos);

		// print value
		printf("%c", _Board->Value);

		// move pointer
		++_Board;
	}	
}