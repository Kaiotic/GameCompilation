#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "Basic.h"
#include "Field.h"

enum boolean 
{
	FALSE = 0,
	TRUE = 1
};

void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg, const char* _sError);
char* getMaskedPassword(const char* _sInputMsg);

int initBoardLabel(Field_t* _Board, size_t _iRows, size_t _iCols);
int initGameBoard(Field_t* _Board, size_t _iRows, size_t _iCols);
void cleanUpGameBoard(Field_t* _Board);

int getKeyCode(void);

#endif //UTILITY_H_INCLUDED
