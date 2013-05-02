#include "ConnectFour.h"
#include "stdheader.h"

const size_t cRows = 6;
const size_t cCols = 7;
Field_t* g_Board;

/*****************************************************************************
void startConnectFour(void)
    Description :
		Starts a game of ConnectFour.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void startConnectFour(void)
{
	initGameBoard(g_Board, cRows, cCols);

	system("CLS");
	printf("\n\t### CONNECT FOUR ###");

	printf("\n\n");
	system("PAUSE");

	cleanUpGameBoard(g_Board);
}