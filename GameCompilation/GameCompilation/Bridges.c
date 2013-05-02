#include "Bridges.h"
#include "stdheader.h"

const size_t BridgesFields = 17;
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
	initGameBoard(g_Board, BridgesFields, BridgesFields);

	system("CLS");
	printf("\n\t### BRIDGES ###");

	printf("\n\n");
	system("PAUSE");

	cleanUpGameBoard(g_Board);
}