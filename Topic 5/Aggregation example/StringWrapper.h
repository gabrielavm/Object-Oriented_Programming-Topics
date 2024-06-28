#include "ConsolePrinter.h"

class StringWrapper
{
	const char* str;
	const ConsolePrinter& cp;

public:

	StringWrapper(const char* str, const ConsolePrinter& cp) : str(str), cp(cp) {}
	void print() const;
};
