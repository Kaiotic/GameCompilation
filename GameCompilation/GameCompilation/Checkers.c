#include "Checkers.h"
#include "stdheader.h"

const size_t g_CheckersFields = 8;
Field_t* g_Board;

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

	// allocate memory
	g_Board = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_Board)
	{
		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_Board, g_CheckersFields, g_CheckersFields);
	
	system("CLS");
	
	printGameBoard(g_Board, iBoardSize);

	printf("\n\n");
	system("PAUSE");

	// free the boards memory
	cleanUpGameBoard(g_Board);
}