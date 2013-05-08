#include "Checkers.h"
#include "stdheader.h"

const static size_t g_Fields = 8;
static Field_t* g_Board;
const static Vec2ds16_t g_Offset = { 2, 2 };

/*****************************************************************************
void startCheckers(void)
    Description :
		Starts a game of Checkers.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startCheckers(void)
{
	const size_t iBoardSize = g_Fields * g_Fields;
	
	// allocate memory
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// show error box
		showError("Memory Allocation Failed", "Memory could not be allocated for Checkers.");

		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_Board, g_Fields, g_Fields);
	
	// print for the first time
	system("CLS");
	printBoardLabels(g_Fields, g_Fields);
	printGameBoard(g_Board, &g_Offset, NULL, NULL, iBoardSize);

	// game loop
	while(updateCheckers(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_Board);
}

/*****************************************************************************
int updateCheckers(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateCheckers(size_t _iBoardSize)
{
	static Vec2ds16_t cursorPosition = { 0, 0 }; // last cursor coordinates
	static Vec2ds16_t selectedToken = { -1, -1 }; // the selected game token
	short iInput = 0;

	// user input
	iInput = getKeyCode();

	switch(iInput)
	{
	case 13: // ENTER
		selectedToken = cursorPosition;
		break;
	case 256 + 72: // ARROW UP
		if(cursorPosition.iY > 0)
		{
			--cursorPosition.iY;
		}
		break;
	case 256 + 80: // ARROW DOWN
		if((unsigned short)cursorPosition.iY < g_Fields - 1)
		{
			++cursorPosition.iY;
		}
		break;
	case 256 + 75: // ARROW LEFT
		if(cursorPosition.iX > 0)
		{
			--cursorPosition.iX;
		}
		break;
	case 256 + 77: // ARROW RIGHT
		if((unsigned short)cursorPosition.iX < g_Fields - 1)
		{
			++cursorPosition.iX;
		}
		break;
	case 27: // ESCAPE
		// set static variables to default
		selectedToken.iX = selectedToken.iY = -1;
		cursorPosition.iX = cursorPosition.iY = 0;

		// break game loop
		return FALSE;
	}

	// print board
	printGameBoard(g_Board, &g_Offset, &cursorPosition, &selectedToken, _iBoardSize);

	return TRUE;
}