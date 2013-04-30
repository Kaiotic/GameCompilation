#include "ErrorHandler.h"
#include <time.h>

/*****************************************************************************
void log(const char* _sError)
    Description :
	Logs error messages to error.txt.
    Parameters  : 
    	const char* _sError: The error message to log.
    Returns     : -
*****************************************************************************/
void log(const char* _sError)
{
	FILE* file = NULL;
	time_t lTime = time(NULL);

	// append messages to file
	if(file = fopen("error.txt", "a+"))
	{
		// log error with timestamp
		fprintf(file, "%s - Error: %s", asctime(localtime(&lTime)), _sError);

		// close file
		fclose(file);
	}
}
