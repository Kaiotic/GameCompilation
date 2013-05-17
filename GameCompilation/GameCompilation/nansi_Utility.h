#ifndef NANSI_UTILITY_H_INCLUDED
#define NANSI_UTILITY_H_INCLUDED

#include "Basic.h"
#include "Field.h"
#include "TextColor.h"

void printBoardLabels(size_t _iRows, size_t _iCols);
void printGameBoard(Field_t* _Board, const Vec2ds16_t* _Offset, Vec2ds16_t* _CursorPosition, Vec2ds16_t* _Selected, size_t _iSize);

void setConsoleTextColor(int _iColor);
void setConsoleBackgroundColor(int _iColor);
int setConsoleSize(int _iWidth, int _iHeight);
int setConsoleTitle(const char* _sTitle);
void showError(const char* _sTitle, const char* _sMessage);

#endif //NANSI_UTILITY_H_INCLUDED