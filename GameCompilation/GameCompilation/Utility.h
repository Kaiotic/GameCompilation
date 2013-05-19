#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "Basic.h"
#include "Field.h"
#include "TextColor.h"

void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg, const char* _sError);
char* getMaskedPassword(const char* _sInputMsg);

int initGameBoard(Field_t** _Board, size_t _iRows, size_t _iCols);
void cleanUpGameBoard(Field_t** _Board, size_t _iRows, size_t _iCols);

int getKeyCode(void);

int getIndexByPosition(Field_t** _Board, size_t _iSize, Vec2ds16_t* _Position);

#endif //UTILITY_H_INCLUDED
