#include "Reversi.h"
#include "stdheader.h"

const size_t g_ReversiFields = 8;
Field_t* g_ReversiBoard;

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
	Vec2ds16_t vOffset = { 2, 2 };

	// allocate memory
	g_ReversiBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_ReversiBoard)
	{
		// memory could not be allocated
		return;
	}	
	
	// initialize the board
	initGameBoard(g_ReversiBoard, g_ReversiFields, g_ReversiFields);
	
	// game loop
	while(updateReversi(iBoardSize));

	// free the boards memory
	cleanUpGameBoard(g_ReversiBoard);
}

/*****************************************************************************
int updateReversi(size_t _iBoardSize)
    Description :
		Updates and prints the GameBoard.
    Parameters  : 
		size_t _iBoardSize: The size of the board.
    Returns     : 
		TRUE, if everything went well. FALSE, if not.
*****************************************************************************/
int updateReversi(size_t _iBoardSize)
{
	/* 
		Game Moves
	*/
	static Vec2ds16_t offset = { 2, 2 };
	static Vec2ds16_t lastSelected = { 0, 0 };

	getchar(); // remove this line later

	printGameBoard(g_ReversiBoard, &offset, &lastSelected, _iBoardSize);

	return TRUE;
}