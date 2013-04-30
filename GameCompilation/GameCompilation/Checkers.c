#include "Checkers.h"
#include "stdheader.h"

const size_t CheckersFields = 8;
Field_t* g_Board;

void startCheckers(void)
{
	initGameBoard(g_Board, CheckersFields, CheckersFields);
	system("CLS");
	printf("\n\t### CHECKERS ###");

	printf("\n\n");
	system("PAUSE");

	cleanUpGameBoard(g_Board);
}