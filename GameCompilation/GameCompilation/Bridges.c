#include "Bridges.h"
#include "stdheader.h"

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
	Vec2ds16_t vOffset = { 1, 1 };

	// allocate memory
	g_BridgesBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_BridgesBoard)
	{
		// memory could not be allocated
		return;
	}
	
	// initialize the board
	initGameBoard(g_BridgesBoard, vOffset, g_BridgesFields, g_BridgesFields);
	
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

	getchar(); // remove this line later

	printGameBoard(g_BridgesBoard, _iBoardSize);

	return TRUE;
}