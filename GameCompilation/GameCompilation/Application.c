#include "Application.h"
#include "stdheader.h"

/*****************************************************************************
int startApplication()
    Description :
		Starts the main application.
    Parameters  : -
    Returns     :
		FALSE, if 'X' or 'x' was entered, else TRUE
*****************************************************************************/
int startApplication(void)
{
	char cUserInput = '\0';

	printMenu();
	getUserInput("%c", &cUserInput, "\n\n\tChoose: ", NULL);

	switch(cUserInput)
	{
	case '1':
		startConnectFour();
		break;
	case '2':
		startReversi();
		break;
	case '3':
		startCheckers();
		break;
	case '4':
		startBridges();
		break;
	case 'x':
	case 'X':
	default:
		// quit application
		return FALSE;
	}

	// everything went well
	return TRUE;
}

void printMenu(void)
{
	system("CLS");

	printf("\t### Game Compilation ###");
	printf("\n\n\t(1) Connect Four");
	printf("\n\t(2) Reversi");
	printf("\n\t(3) Checkers");
	printf("\n\t(4) Bridges");
	printf("\n\t(X) Quit");
}