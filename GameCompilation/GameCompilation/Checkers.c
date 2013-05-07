#include "Checkers.h"
#include "stdheader.h"

const size_t g_CheckersFields = 8;
Field_t* g_CheckersBoard;

/*****************************************************************************
void startCheckers(void)
    Description :
		Starts a game of Checkers.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startCheckers(void)
{
	const size_t iBoardSize = g_CheckersFields * g_CheckersFields;
	Vec2ds16_t vOffset = { 2, 2 };

	// allocate memory
	g_CheckersBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_CheckersBoard)
	{
		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_CheckersBoard, g_CheckersFields, g_CheckersFields);
	
	// game loop
	while(updateCheckers(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_CheckersBoard);
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
	/*
		Game Moves
	*/
	static Vec2ds16_t offset = { 2, 2 }; // positional offset
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
		if((unsigned short)cursorPosition.iY < g_CheckersFields - 1)
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
		if((unsigned short)cursorPosition.iX < g_CheckersFields - 1)
		{
			++cursorPosition.iX;
		}
		break;
	}


	printGameBoard(g_CheckersBoard, &offset, &cursorPosition, _iBoardSize);

	return TRUE;
}