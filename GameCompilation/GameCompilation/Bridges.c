#include "Bridges.h"
#include "stdheader.h"
#include <conio.h>

const static size_t g_Fields = 17;
const static Vec2ds16_t g_Offset = { 2, 2 };
Field_t** g_BridgesBoard;

/*****************************************************************************
void startBridges(void)
    Description :
		Starts a game of Bridges.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startBridges(void)
{
	size_t i = 0;

	// allocate memory
	g_BridgesBoard = (Field_t**)calloc(g_Fields, sizeof(Field_t));
	for(i = 0; i < g_Fields; ++i)
	{
		g_BridgesBoard[i] = (Field_t*)calloc(g_Fields, sizeof(Field_t));
	}

	if(!g_BridgesBoard)
	{
		// show error box
		showError("Memory Allocation Failed", "Memory could not be allocated for Bridges.");

		// quit
		return;
	}
	
	// initialize the board
	initGameBoard(g_BridgesBoard, g_Fields, g_Fields);

	// print for the first time
	system("CLS");
	printBoardLabels(g_Fields, g_Fields);
	printGameBoard(g_BridgesBoard, &g_Offset, NULL, NULL, g_Fields, g_Fields);

	// game loop
	while(updateBridges(g_Fields * g_Fields));

	// free the boards memory
	cleanUpGameBoard(g_BridgesBoard, g_Fields);
}

/*****************************************************************************
int updateBridges(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateBridges(size_t _iBoardSize)
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
	printGameBoard(g_BridgesBoard, &g_Offset, &cursorPosition, &selectedToken, g_Fields, g_Fields);

	return TRUE;
}