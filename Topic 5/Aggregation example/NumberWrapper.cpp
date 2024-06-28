#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#pragma warning (disable:4996)

NumberWrapper::NumberWrapper(int n, const ConsolePrinter& cp) : n(n), consolePrinter(cp) 
{}

int NumberWrapper::getNumber() const
{
	return n;
}

void NumberWrapper::print() const
{
	consolePrinter.print(std::to_string(n).c_str());
}
