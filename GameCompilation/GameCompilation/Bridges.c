#include "Bridges.h"
#include "stdheader.h"
#include <conio.h>

const size_t g_BridgesFields = 17;
Field_t* g_BridgesBoard; 

/*****************************************************************************
void startBridges(void)
    Description :
		Starts a game of Bridges.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startBridges(void)
{
	const size_t iBoardSize = g_BridgesFields * g_BridgesFields;

	// allocate memory
	g_BridgesBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_BridgesBoard)
	{
		// memory could not be allocated
		return;
	}
	
	// initialize the board
	initGameBoard(g_BridgesBoard, g_BridgesFields, g_BridgesFields);

	// game loop
	while(updateBridges(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_BridgesBoard);
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
	/*
		Game Moves
	*/
	static Vec2ds16_t offset = { 2, 1 }; // positional offset
	static Vec2ds16_t cursorPosition = { 0, 0 }; // last cursor coordinates
	short iInput = 0;

	iInput = getKeyCode();

	switch(iInput)
	{
	case 256 + 72: // ARROW UP
		if(cursorPosition.iY > 0)
		{
			--cursorPosition.iY;
		}
		break;
	case 256 + 80: // ARROW DOWN
		if((unsigned short)cursorPosition.iY < g_BridgesFields - 1)
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
		if((unsigned short)cursorPosition.iX < g_BridgesFields - 1)
		{
			++cursorPosition.iX;
		}
		break;
	}

	printGameBoard(g_BridgesBoard, &offset, &cursorPosition, _iBoardSize);

	return TRUE;
}