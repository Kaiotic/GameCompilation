#include "ConnectFour.h"
#include "stdheader.h"

const static size_t g_iRows = 6;
const static size_t g_iCols = 7;
static Field_t* g_Board;
const static Vec2ds16_t g_Offset = { 2, 2 };

/*****************************************************************************
void startConnectFour(void)
    Description :
		Starts a game of ConnectFour.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startConnectFour(void)
{
	const size_t iBoardSize = g_iRows * g_iCols;

	// allocate memory
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// show error box
		showError("Memory Allocation Failed", "Memory could not be allocated for ConnectFour.");

		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_Board, g_iRows, g_iCols);
	
	// print for the first time
	system("CLS");
	printBoardLabels(g_iCols, g_iRows);
	printGameBoard(g_Board, &g_Offset, NULL, NULL, iBoardSize);

	// game loop
	while(updateConnectFour(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_Board);
}

/*****************************************************************************
int updateConnectFour(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateConnectFour(size_t _iBoardSize)
{
	static Vec2ds16_t cursorPosition = { 0, 0 }; // last cursor coordinates
	short iInput = 0;
	Vec2ds16_t dropPosition;

	// user input
	iInput = getKeyCode();

	switch(iInput)
	{
	case 13:
		dropPosition = cursorPosition;
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
	printGameBoard(g_Board, &g_Offset, &cursorPosition, NULL, _iBoardSize);

	return TRUE;
}