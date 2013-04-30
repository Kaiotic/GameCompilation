#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

enum boolean 
{
	FALSE = 0,
	TRUE = 1
};

void getUserInput(const char* _sFormat, void* _vInput, const char* _sInputMsg, const char* _sError);
char* getMaskedPassword(const char* _sInputMsg);

#endif //UTILITY_H_INCLUDED