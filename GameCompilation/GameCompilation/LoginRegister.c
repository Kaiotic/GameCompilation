#include "LoginRegister.h"
#include "Basic.h"
#include "Utility.h"
#include "Application.h"
#include <string.h>

/*****************************************************************************
int showLogin(void)
    Description :
		Shows the Login screen.
    Parameters  : -
    Returns     :
		TRUE, if user was logged in successfully. FALSE, if not.
*****************************************************************************/
int showLogin(void)
{
	// 20 characters for Username and Password
	char* sUsername = (char*)calloc(20, sizeof(sUsername));
	char* sPassword = (char*)calloc(20, sizeof(sPassword));

	// to catch errors
	static int iErr = 0;

	system("CLS");

	printf("\t### Login ###");

	// there was an error before
	if(iErr == 1)
	{
		printf("\n\n\tUsername already exists.\n");
	}

	getUserInput("%s", sUsername, "\n\n\tUsername: ", NULL);
	sPassword = getMaskedPassword("\n\tPassword: ");

	/* 
		if sUsername && sPassword don't exist in DB
			iErr = 1;
			return FALSE;
	*/

	return TRUE;
}

/*****************************************************************************
int showRegister(void)
    Description :
		Shows the Register screen.
    Parameters  : -
    Returns     :
		TRUE, if user was registered successfully. FALSE, if not.
*****************************************************************************/
int showRegister(void)
{
	// 20 characters for Username and Password
	char* sUsername = (char*)calloc(20, sizeof(sUsername));
	char* sPassword = (char*)calloc(20, sizeof(sPassword));
	char* sPass = (char*)calloc(20, sizeof(sPass));
	
	// to catch errors
	static int iErr = 0;

	system("CLS");

	printf("\t### Register ###");

	// there was an error before
	if(iErr == 1)
	{
		printf("\n\n\tPasswords did not match.\n");
	}

	// get username, password and confirm password
	getUserInput("%s", sUsername, "\n\n\tUsername: ", "Username already exists.\n");
	sPassword = getMaskedPassword("\n\tPassword: ");
	sPass = getMaskedPassword("\n\tConfirm Password: ");

	if(strcmp(sPassword, sPass) != 0)
	{
		// passwords don't match
		iErr = 1;
		return FALSE;
	}

	/* 
		if sUsername already exists
			return FALSE;

		hash and salt PW

		create new user in DB
	*/
	return TRUE;
}