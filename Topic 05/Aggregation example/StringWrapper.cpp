#include "StringWrapper.h"

void StringWrapper::print() const
{
	cp.print(str);
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
