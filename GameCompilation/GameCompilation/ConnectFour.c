#include "ConnectFour.h"
#include "Utility.h"
#include "nansi_Utility.h"
#include "Boolean.h"

const static size_t g_iRows = 6;
const static size_t g_iCols = 7;
const static Vec2ds16_t g_Offset = { 2, 2 };
static char g_cPlayerSymbol;
Field_t** g_ConnectFourBoard;

/*****************************************************************************
void startConnectFour(void)
    Description :
		Starts a game of ConnectFour.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startConnectFour(void)
{
	size_t i = 0;

	// allocate memory
	g_ConnectFourBoard = (Field_t**)calloc(g_iCols, sizeof(Field_t));
	for(i = 0; i < g_iCols; ++i)
	{
		g_ConnectFourBoard[i] = (Field_t*)calloc(g_iRows, sizeof(Field_t));
	}

	// memory allocation error
	if(!g_ConnectFourBoard)
	{
		// show error box
		showError("Memory Allocation Failed", "Memory could not be allocated for ConnectFour.");

		// quit
		return;
	}

	// initialize the board
	initGameBoard(g_ConnectFourBoard, g_iRows, g_iCols);
	
	// print for the first time
	system("CLS");
	printBoardLabels(g_iCols, g_iRows);
	printGameBoard(g_ConnectFourBoard, &g_Offset, NULL, NULL, g_iRows, g_iCols);

	// player 'X' starts
	g_cPlayerSymbol = 'X';

	// game loop
	while(updateConnectFour());

	// print once more
	printGameBoard(g_ConnectFourBoard, &g_Offset, NULL, NULL, g_iRows, g_iCols);

	printWinMessage();

	// free the boards memory
	cleanUpGameBoard(g_ConnectFourBoard, g_iRows);
}

/*****************************************************************************
int updateConnectFour(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : -
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateConnectFour(void)
{
	static Vec2ds16_t cursorPosition = { 0, 0 }; // last cursor coordinates
	Vec2ds16_t dropPosition;
	short iInput = 0;

	// user input
	iInput = getKeyCode();

	switch(iInput)
	{
	case 13: // ENTER
		dropPosition = cursorPosition;

		// find y-position where token "lands"
		while(g_ConnectFourBoard[dropPosition.iX][dropPosition.iY].Value == '\0' && (unsigned short)dropPosition.iY < g_iRows)
		{
			++dropPosition.iY;
		}

		// place element "on top" of found y-position
		if(g_ConnectFourBoard[dropPosition.iX][dropPosition.iY - 1].Value == '\0')
		{
			// set symbol and color
			g_ConnectFourBoard[dropPosition.iX][dropPosition.iY - 1].Value = g_cPlayerSymbol;
			if(g_cPlayerSymbol == 'O')
			{
				g_ConnectFourBoard[dropPosition.iX][dropPosition.iY - 1].Color = Yellow;
			}
			else if(g_cPlayerSymbol == 'X')
			{
				g_ConnectFourBoard[dropPosition.iX][dropPosition.iY - 1].Color = Green;				
			}
			
			// check if someone won
			if(checkWin(g_ConnectFourBoard))
			{
				// end game
				cursorPosition.iX = cursorPosition.iY = 0;
				return FALSE;
			}

			// change player symbol
			g_cPlayerSymbol = g_cPlayerSymbol == 'X' ? 'O' : 'X';
		}
		break;
	case 256 + 75: // ARROW LEFT
		if(cursorPosition.iX > 0)
		{
			--cursorPosition.iX;
		}
		break;
	case 256 + 77: // ARROW RIGHT
		if((unsigned short)cursorPosition.iX < g_iCols - 1)
		{
			++cursorPosition.iX;
		}
		break;
	case 27: // ESCAPE
		// set static variables to default
		cursorPosition.iX = cursorPosition.iY = 0;

		// break game loop
		return FALSE;
	}

	// print board
	printGameBoard(g_ConnectFourBoard, &g_Offset, &cursorPosition, NULL, g_iRows, g_iCols);

	return TRUE;
}

/*****************************************************************************
int checkWin(Field_t** _board)
    Description :
		Checks all possibilities for a win (4 in a line).
    Parameters  : 
		Field_t** _Board: The board to check.
    Returns     : 
		TRUE, if there is a line. FALSE, if not.
*****************************************************************************/
int checkWin(Field_t** _Board)
{
	size_t i = 0;
	size_t j = 0;
	char cValue = '\0';

	// check for all elements
	for(i = 0; i < g_iCols; ++i)
	{
		for(j = 0; j < g_iRows; ++j)
		{
			if(_Board[i][j].Value != '\0')
			{
				// first value thats not empty
				cValue = _Board[i][j].Value;

				// check for possible lines
				if(isMatch(i, j, cValue))
				{
					// line found -> game ends
					return TRUE;
				}
			}
		}
	}

	// no line found -> continue
	return FALSE;
}

/*****************************************************************************
int isLine(short _iX, short _iY, short _dirX, short _dirY, char _cVal)
    Description :
		Checks if there are 4 occurrences of _cVal in a line starting at _iX / _iY.
    Parameters  : 
		short _iX: The X position to start at.
		short _iY: The Y position to start at.
		short _stepX: The X direction to check.
		short _stepY: The Y direction to check.
		char _cVal: The value to check for.
    Returns     : 
		TRUE, if there is a line. FALSE, if not.
*****************************************************************************/
int isLine(short _iX, short _iY, short _dirX, short _dirY, char _cVal)
{
	size_t i = 0;
	unsigned short iX;
	unsigned short iY;

	for(i = 0; i < 4; ++i)
	{
		// next coordinates
		iX = _iX + i * _dirX;
		iY = _iY + i * _dirY;

		// FALSE if out of bounds and not a line yet
		if(iX > g_iRows || iY > g_iCols)
		{
			return FALSE;
		}

		// check if values are equal
		if(g_ConnectFourBoard[iX][iY].Value != _cVal)
		{
			// not 4 of the same
			return FALSE;
		}
	}

	// 4 in a row found
	return TRUE;
}

/*****************************************************************************
int isMatch(short _iX, short _iY, char _cVal)
    Description :
		Checks any direction for 4 occurrences of _cVal in a row.
    Parameters  : 
		short _iX: The X position to start at.
		short _iY: The Y position to start at.
		char _cVal: The value to check for.
    Returns     : 
		TRUE, if any direction is a match. FALSE, if not.
*****************************************************************************/
int isMatch(short _iX, short _iY, char _cVal)
{
	return isLine(_iX, _iY, 1, 0, _cVal) || // horizontal
		isLine(_iX, _iY, 0, 1, _cVal) || // vertical
		isLine(_iX, _iY, 1, 1, _cVal) || // diagonal down
		isLine(_iX, _iY, 1, -1, _cVal); // diagonal up
}

/*****************************************************************************
void printWinMessage(void)
    Description :
		Prints the win message.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void printWinMessage(void)
{
	printf("%c has won the game! Congratulations!\n\n", g_cPlayerSymbol);
	system("PAUSE");
}