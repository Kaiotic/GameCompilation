#include "nansi_Utility.h"
#include <Windows.h>

const static float g_RowMultiplier = 3;
const static float g_ColMultiplier = 1.5;

/*****************************************************************************
void printGameBoard(Field_t* _Board, size_t _iSize)
	Description :
		Prints the given board to the console.
	Parameters : 
		Field_t* _Board: The board to print.
		size_t _iSize: The size of the board.
	Returns : -
*****************************************************************************/
void printGameBoard(Field_t* _Board, const Vec2ds16_t* _Offset, Vec2ds16_t* _CursorPosition, Vec2ds16_t* _Selected, size_t _iSize)
{
	size_t i = 0;
	COORD pos; // console coordinates
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	for(i = 0; i < _iSize; ++i)
	{
		// if there is a selection and the selection equals the boards position OR
		// if there is no selection and the boards position is [0,0]
		if((_CursorPosition && _Board->Position.iX == _CursorPosition->iX && _Board->Position.iY == _CursorPosition->iY)
			|| !_CursorPosition && _Board->Position.iX == 0 && _Board->Position.iY == 0)
		{
			// color it red
			setConsoleTextColor(Red);
		}
		else if(_Selected && _Selected->iX != -1 && _Selected->iY != -1 && _Board->Position.iX == _Selected->iX && _Board->Position.iY == _Selected->iY) 
		{
			// color it blue
			setConsoleTextColor(Blue);
		}
		else 
		{
			// default gray
			setConsoleTextColor(Gray);
		}
		

		// set coordinates
		pos.X = (short)(_Board->Position.iX + g_RowMultiplier) * _Offset->iX;
		pos.Y = (short)(_Board->Position.iY + g_ColMultiplier) * _Offset->iY;

		// move cursor to position
		SetConsoleCursorPosition(hOutput, pos);
		
		// print value
		printf("%c", _Board->Value);

		// move pointer
		++_Board;
	}
}

/*****************************************************************************
void printBoardLabels(size_t _iRows, size_t _iCols)
	Description:
		Prints the board's labels
	Parameters:
		size_t _iRows : The number of rows.
		size_t _iCols : The number of cols.
	Returns: -
*****************************************************************************/
void printBoardLabels(size_t _iRows, size_t _iCols)
{
	size_t i = 0;
	COORD pos; // console coordinates
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle
	char colLabel = 'A'; // start-character
	Vec2ds16_t offset = { 2, 2 };

	// Add labels to boardLabels
	for(i = 0; i < _iRows ; ++i)
	{
		// set coordinates
		pos.X = (short)(i + g_RowMultiplier) * offset.iX;
		pos.Y = 0;

		// move cursor to position
		SetConsoleCursorPosition(hOutput, pos);

		// print value
		printf("%c", (colLabel + i));
	}

	for(i = 0; i < _iCols; ++i) 
	{
		// set coordinates
		pos.X = 0;
		pos.Y = (short)(i + g_ColMultiplier) * offset.iY;

		// move cursor to position
		SetConsoleCursorPosition(hOutput, pos);

		// print value
		printf("%i", i + 1);
	}
}

/*****************************************************************************
void setConsoleTextColor(int _iColor)
	Description :
		Changes the text color of the console.
	Parameters : 
		int _iColor: The color code to change to.
	Returns : -
*****************************************************************************/
void setConsoleTextColor(int _iColor)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	// change text color
	SetConsoleTextAttribute(hOutput, _iColor);
}

/*****************************************************************************
void setConsoleBackground(int _iColor)
	Description :
		Changes the background color of the console.
	Parameters : 
		int _iColor: The color code to change to.
	Returns : -
*****************************************************************************/
void setConsoleBackgroundColor(int _iColor)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	// change background color
	SetConsoleTextAttribute(hOutput, (_iColor << 4));
}

void setConsoleSize(int _iWidth, int _iHeight)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT window = { 0, 0, _iWidth, _iHeight };
	COORD buffer = { _iWidth + 1, _iHeight + 1 };
	DWORD err;

	if(!SetConsoleScreenBufferSize(hOutput, buffer))
	{
		err = GetLastError();
	}
	if(!SetConsoleWindowInfo(hOutput, TRUE, &window))
	{
		err = GetLastError();
	}
}