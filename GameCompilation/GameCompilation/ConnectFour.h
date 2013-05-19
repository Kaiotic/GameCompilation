#ifndef CONNECTFOUR_H_INCLUDED
#define CONNECTFOUR_H_INCLUDED

#include "Basic.h"
#include "Vec2ds16.h"
#include "Field.h"

void startConnectFour(void);
int updateConnectFour(void);

int checkWin(Field_t** _Board);

int isLine(short _iX, short _iY, short _dirX, short _dirY, char _cVal);
int isMatch(short _iX, short _iY, char _cVal);

void printWinMessage(void);

#endif //CONNECTFOUR_H_INCLUDED