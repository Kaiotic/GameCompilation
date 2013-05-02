#include "Reversi.h"
#include "stdheader.h"

const size_t g_ReversiFields = 8;
Field_t* g_Board;

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

	// allocate memory
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// memory could not be allocated
		return;
	}	
	
	// initialize the board
	initGameBoard(g_Board, g_ReversiFields, g_ReversiFields);

	system("CLS");
	
	printGameBoard(g_Board, iBoardSize);

	printf("\n\n");
	system("PAUSE");

	// free the boards memory
	cleanUpGameBoard(g_Board);
}