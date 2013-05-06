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
	initGameBoard(g_ConnectFourBoard, vOffset, g_iRows, g_iCols);
	
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

	getchar(); // remove this line later

	printGameBoard(g_ConnectFourBoard, _iBoardSize);

	return TRUE;
}