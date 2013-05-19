#include "Application.h"
#include "stdheader.h"
#include <string.h>

void showHelp(void);

/*****************************************************************************
int startApplication(void)
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
	case '5':
		showHelp();
		break;
	case 'x':
	case 'X':
		// quit application
		return FALSE;
	default:
		break;
	}

	// everything went well
	return TRUE;
}

/*****************************************************************************
void printMenu(void)
    Description :
		Prints the Main Menu to the console.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void printMenu(void)
{
	system("CLS");

	printf("\t### Game Compilation ###");
	printf("\n\n\t(1) Connect Four");
	printf("\n\t(2) Reversi");
	printf("\n\t(3) Checkers");
	printf("\n\t(4) Bridges");
	printf("\n\t(5) Help");
	printf("\n\t(X) Quit");
}

/*****************************************************************************
void showHelp(void)
    Description :
		Prints the help menu to the console.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void showHelp(void)
{
	system("CLS");

	printf("## To Be Implemented ##\n\n");

	system("PAUSE");	
}

	