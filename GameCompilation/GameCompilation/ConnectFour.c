#include "ConnectFour.h"
#include "stdheader.h"

const size_t g_iRows = 6;
const size_t g_iCols = 7;
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
	const size_t iBoardSize = g_iRows * g_iCols;

	// allocate memory
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_Board, g_iRows, g_iCols);

	system("CLS");
	
	printGameBoard(g_Board, iBoardSize);

	printf("\n\n");
	system("PAUSE");

	// free the boards memory
	cleanUpGameBoard(g_Board);
}