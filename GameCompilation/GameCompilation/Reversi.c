#include "Reversi.h"
#include "stdheader.h"

const size_t g_ReversiFields = 8;
Field_t* g_ReversiBoard;

/*****************************************************************************
void startReversi(void)
    Description :
		Starts a game of Reversi.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startReversi(void)
{
	const size_t iBoardSize = g_ReversiFields * g_ReversiFields;
	Vec2ds16_t vOffset = { 2, 2 };

	// allocate memory
	g_ReversiBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_ReversiBoard)
	{
		// memory could not be allocated
		return;
	}	
	
	// initialize the board
	initGameBoard(g_ReversiBoard, g_ReversiFields, g_ReversiFields);
	
	// game loop
	while(updateReversi(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_ReversiBoard);
}

/*****************************************************************************
int updateReversi(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateReversi(size_t _iBoardSize)
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
		if((unsigned short)cursorPosition.iY < g_ReversiFields - 1)
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
		if((unsigned short)cursorPosition.iX < g_ReversiFields - 1)
		{
			++cursorPosition.iX;
		}
		break;
	}

	printGameBoard(g_ReversiBoard, &offset, &cursorPosition, _iBoardSize);

	return TRUE;
}