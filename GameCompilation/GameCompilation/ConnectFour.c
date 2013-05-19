#include "ConnectFour.h"
#include "stdheader.h"

const static size_t g_iRows = 6;
const static size_t g_iCols = 7;
Field_t* g_ConnectFourBoard;
const static Vec2ds16_t g_Offset = { 2, 2 };

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
	g_ConnectFourBoard = (Field_t*)calloc(iBoardSize, sizeof(Field_t));
	if(!g_ConnectFourBoard)
	{
		// show error box
		showError("Memory Allocation Failed", "Memory could not be allocated for ConnectFour.");

		// memory could not be allocated
		return;
	}

	// initialize the board
	initGameBoard(g_ConnectFourBoard, g_iRows, g_iCols);
	
	// print for the first time
	system("CLS");
	printBoardLabels(g_iCols, g_iRows);
	printGameBoard(g_ConnectFourBoard, &g_Offset, NULL, NULL, iBoardSize);

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
	static Vec2ds16_t cursorPosition = { 0, 0 }; // last cursor coordinates
	short iInput = 0;
	size_t iIndex = 0;
	size_t iNext = 0;
	Vec2ds16_t dropPosition;

	// user input
	iInput = getKeyCode();

	switch(iInput)
	{
	case 13:
		// position to drop the token
		dropPosition = cursorPosition;

		// get element index
		iIndex = getIndexByPosition(g_ConnectFourBoard, _iBoardSize, &dropPosition);

		// simulate the "falling token" until it hits another one or the ground
		while(g_ConnectFourBoard[iIndex].Value == '\0' && (unsigned short)dropPosition.iY < g_iRows)
		{
			// remember last empty position
			iNext = iIndex;

			// fall one row
			++dropPosition.iY;

			// get new index
			iIndex = getIndexByPosition(g_ConnectFourBoard, _iBoardSize, &dropPosition);
		}

		// set value on new position to something
		g_ConnectFourBoard[iNext].Value = 'O';

		break;
	case 256 + 75: // ARROW LEFT
		if(cursorPosition.iX > 0)
		{
			--cursorPosition.iX;
		}
		break;
	case 256 + 77: // ARROW RIGHT
		if((unsigned short)cursorPosition.iX < g_iCols - 1)
		{
			++cursorPosition.iX;
		}
		break;
	case 27: // ESCAPE
		// set static variables to default
		cursorPosition.iX = cursorPosition.iY = 0;

		// break game loop
		return FALSE;
	}

	// print board
	printGameBoard(g_ConnectFourBoard, &g_Offset, &cursorPosition, NULL, _iBoardSize);

	return TRUE;
}