#include "stdheader.h"
#include "nansi_Utility.h"
#include "Application.h"
#include "LoginRegister.h"

void showStartScreen(void);
int initConsole(void);

int main(void)
{
	int iChoice = 0;

	// size console window to 100x40
	if(!initConsole())
	{
		// show error box
		showError("Error", "Console Window could not be initialized.\nExiting program.");
		
		return EXIT_FAILURE;
	}	

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

/*****************************************************************************
int initConsole(void)
    Description :
		Initializes the console window.
    Parameters  : -
    Returns     :
		TRUE, if everything initialized correctly.
		FALSE, if not.
*****************************************************************************/
int initConsole(void) 
{
	if(!setConsoleSize(100, 40))
	{
		// console size could not be set
		return FALSE;
	}

	if(!setConsoleTitle("Game Compilation"))
	{
		// console title could not be set
		return FALSE;
	}

	// everything went well
	return TRUE;
}