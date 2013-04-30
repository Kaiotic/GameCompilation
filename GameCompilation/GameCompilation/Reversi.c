#include "Reversi.h"
#include "stdheader.h"

const size_t ReversiFields = 8;
Field_t* g_Board;

void startReversi(void)
{
	initGameBoard(g_Board, ReversiFields, ReversiFields);

	system("CLS");
	printf("\n\t### REVERSI ###");

	printf("\n\n");
	system("PAUSE");

	cleanUpGameBoard(g_Board);
}