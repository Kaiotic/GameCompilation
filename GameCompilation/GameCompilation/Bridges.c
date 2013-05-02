#include "Bridges.h"
#include "stdheader.h"

const size_t g_BridgesFields = 17;
Field_t* g_Board; 

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
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// memory could not be allocated
		return;
	}
	
	// initialize the board
	initGameBoard(g_Board, g_BridgesFields, g_BridgesFields);

	system("CLS");
	
	printGameBoard(g_Board, iBoardSize);

	printf("\n\n");
	system("PAUSE");

	// free the boards memory
	cleanUpGameBoard(g_Board);
}