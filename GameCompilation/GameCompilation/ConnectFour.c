#include "ConnectFour.h"
#include "stdheader.h"

const size_t g_iRows = 6;
const size_t g_iCols = 7;
Field_t* g_ConnectFourBoard;

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
	Vec2ds16_t vOffset = { 2, 2 };

	// allocate memory
	g_ConnectFourBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_ConnectFourBoard)
	{
		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_ConnectFourBoard, g_iRows, g_iCols);
	
	// game loop
	while(updateConnectFour(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_ConnectFourBoard);
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
		if((unsigned short)cursorPosition.iY < g_iCols - 1)
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
		if((unsigned short)cursorPosition.iX < g_iRows - 1)
		{
			++cursorPosition.iX;
		}
		break;
	}

	printGameBoard(g_ConnectFourBoard, &offset, &cursorPosition, _iBoardSize);

	return TRUE;
}