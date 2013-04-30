#include "Bridges.h"
#include "stdheader.h"

const size_t cFields = 17;
Field_t* g_Board; 

void startBridges(void)
{
	init();
	system("CLS");
	printf("\n\t### BRIDGES ###");

	printf("\n\n");
	system("PAUSE");

	cleanUp();
}

int init(void)
{
	size_t i = 0; // rows
	size_t j = 0; // cols

	Field_t* ptrFirst;

	// allocate memory
	g_Board = (Field_t*)calloc(cFields * cFields, sizeof(Field_t));

	if(!g_Board)
	{
		// initialization error
		return FALSE;
	}

	// remember first element
	ptrFirst = g_Board;

	for(i = 0; i < cFields; ++i)
	{
		for(j = 0; j < cFields; ++j)
		{
			// initialize board
			g_Board->Position.iX = i;
			g_Board->Position.iY = j;
			g_Board->Value = ' ';

			// move pointer
			++g_Board;
		}
	}

	// reset pointer to first element
	g_Board = ptrFirst;

	// everything went well
	return TRUE;
}

void cleanUp(void)
{
	if(g_Board)
	{
		free(g_Board);
	}
}