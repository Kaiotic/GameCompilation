#include "Checkers.h"
#include "stdheader.h"

const size_t g_CheckersFields = 8;
Field_t* g_CheckersBoard;

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
	Vec2ds16_t vOffset = { 2, 2 };

	// allocate memory
	g_CheckersBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_CheckersBoard)
	{
		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_CheckersBoard, g_CheckersFields, g_CheckersFields);
	
	// game loop
	while(updateCheckers(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_CheckersBoard);
}

/*****************************************************************************
int updateCheckers(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateCheckers(size_t _iBoardSize)
{
	/*
		Game Moves
	*/
	static Vec2ds16_t offset = { 2, 2 };
	static Vec2ds16_t lastSelected = { 0, 0 };
	getchar(); // remove this line later

	printGameBoard(g_CheckersBoard, &offset, &lastSelected, _iBoardSize);

	return TRUE;
}