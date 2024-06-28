#pragma once

class ConsolePrinter
{
	bool (*shouldCensore)(char ch);

public:

	ConsolePrinter();
	ConsolePrinter(bool (*pred)(char ch));

	void print(const char* str) const;
};
