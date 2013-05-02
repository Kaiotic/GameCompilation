#ifndef NANSI_UTILITY_H_INCLUDED
#define NANSI_UTILITY_H_INCLUDED

#include "Basic.h"
#include "Field.h"
#include <Windows.h>

enum TextColor
{
	Black = 0,
	DarkBlue = 1,
	DarkGreen = 2,
	DarkTeal = 3,
	DarkRed = 4,
	DarkPink = 5,
	DarkYellow = 6,
	Gray = 7,
	Darkgray = 8,
	Blue = 9,
	Green = 10,
	Teal = 11,
	Red = 12,
	Pink = 13,
	Yellow = 14,
	White = 15
};

void printGameBoard(Field_t* _Board, size_t _iSize);
void setConsoleTextColor(int _iColor);
void setConsoleBackgroundColor(int _iColor);

#endif //NANSI_UTILITY_H_INCLUDED