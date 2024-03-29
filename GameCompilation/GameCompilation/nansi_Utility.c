#include "nansi_Utility.h"
#include <Windows.h>

const static float g_RowMultiplier = 3;
const static float g_ColMultiplier = 1.5;

/*****************************************************************************
void printGameBoard(Field_t* _Board, size_t _iSize)
	Description :
		Prints the given board to the console.
	Parameters : 
		Field_t** _Board: The board to print.
		const Vec2ds16_t* _Offset: The positional offset.
		Vec2ds16_t* _CursorPosition: Current position of the cursor.
		Vec2ds16_t* _Selected: The last selected element.
		size_t _iRows: Number of rows.
		size_t _iCols: Number of columns.
	Returns : -
*****************************************************************************/
void printGameBoard(Field_t** _Board, const Vec2ds16_t* _Offset, Vec2ds16_t* _CursorPosition, Vec2ds16_t* _Selected, size_t _iRows, size_t _iCols)
{
	size_t i = 0;
	size_t j = 0;
	COORD pos; // console coordinates
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	for(j = 0; j < _iRows; ++j)
	{
		pos.Y = (short)(j + g_ColMultiplier) * _Offset->iY;
		for(i = 0; i < _iCols; ++i)
		{
			pos.X = (short)(i + g_RowMultiplier) * _Offset->iX;

			// position is selected
			if((_CursorPosition && _CursorPosition->iX == i && _CursorPosition->iY == j) ||
				(!_CursorPosition && i == 0 && j == 0))
			{
				setConsoleBackgroundColor(Red);
			}
			// last selected element
			else if(_Selected && _Selected->iX != -1 && _Selected->iY != -1 && _Selected->iX == i && _Selected->iY == j)
			{
				setConsoleBackgroundColor(Blue);
			}
			// default
			else
			{
				setConsoleTextColor(_Board[i][j].Color);
			}

			// move cursor
			SetConsoleCursorPosition(hOutput, pos);

			// print value
			printf("%c", _Board[i][j].Value);
		}
	}

	printf("\n\n\n\n");
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

	pos.Y = 0; // letters on x-axis
	for(i = 0; i < _iRows ; ++i)
	{
		// set coordinates
		pos.X = (short)(i + g_RowMultiplier) * offset.iX;
		
		// move cursor to position
		SetConsoleCursorPosition(hOutput, pos);

		// print value
		printf("%c", (colLabel + i));
	}

	pos.X = 0; // numbers on y-axis
	for(i = 0; i < _iCols; ++i) 
	{
		// set coordinates
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

/*****************************************************************************
void setConsoleSize(int _iWidth, int _iHeight)
	Description:
		Resizes the ConsoleWindow.
	Parameters:
		int _iWidth : The new console width.
		int _iHeight : The new console height.
	Returns: -
*****************************************************************************/
int setConsoleSize(int _iWidth, int _iHeight)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle
	SMALL_RECT window = { 0, 0, _iWidth, _iHeight }; // window size
	COORD buffer = { _iWidth + 1, _iHeight + 1 }; // screen buffer (must be greater than screen size)

	// set the screen buffer
	if(!SetConsoleScreenBufferSize(hOutput, buffer))
	{
		return FALSE;
	}

	// set the actual size
	if(!SetConsoleWindowInfo(hOutput, TRUE, &window))
	{
		return FALSE;
	}

	return TRUE;
}

/*****************************************************************************
int setConsoleTitle(const char* _sTitle)
    Description :
		Sets the console title to the given string.
    Parameters  :
		const char* _sTitle: The new console title.
    Returns     : 
		TRUE, if title was set correctly.
		FALSE, if not.
*****************************************************************************/
int setConsoleTitle(const char* _sTitle)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // console handle

	if(!SetConsoleTitle(_sTitle))
	{
		return FALSE;
	}

	// everything went well
	return TRUE;
}

/*****************************************************************************
void showError(const char* _sTitle, const char* _sMessage)
    Description :
		Pops up a MessageBox with the given Title and Message.
    Parameters  :
		const char* _sTitle: The MessageBox title.
		const char* _sMessage: The MessageBox message.
    Returns     : -
*****************************************************************************/
void showError(const char* _sTitle, const char* _sMessage)
{
	HWND hWnd = GetConsoleWindow(); // handle window

	MessageBox(hWnd, _sMessage, _sTitle, MB_ICONERROR); // message box pop up
}