#include "stdheader.h"
#include "nansi_Utility.h"
#include "Application.h"
#include "LoginRegister.h"

void showStartScreen(void);

int main()
{
	int iChoice = 0;

	// size console window to 100x40
	setConsoleSize(100, 40);
	
	// LogIn / Register Menu
	showStartScreen();

	do
	{
		// choose between LogIn and Register
		getUserInput("%i", &iChoice, "\tChoose: ", "\n\tYour input is invalid. Please choose again.\n");
	}
	while(iChoice != 1 && iChoice != 2);
	
	// LogIn / Register
	if(iChoice == 1)
	{
		// loop until valid login
		while(!showLogin());
	}
	else
	{
		// loop until valid registration
		while(!showRegister());
	}

	// loop until user quits manually
	while(startApplication());

	return EXIT_SUCCESS;
}

/*****************************************************************************
void showStartScreen(void)
    Description :
		Prints the Start Screen to the Console.
    Parameters  : -
    Returns     : -
*****************************************************************************/
void showStartScreen(void)
{
	printf("\t### Game Compilation ###");
	printf("\n\n\t(1) Login");
	printf("\n\t(2) Register\n");
}