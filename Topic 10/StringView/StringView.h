#pragma once
#include <iostream>
#include <fstream>
#include <exception>

class StringView
{
	const char* begin;
	const char* end;
public:
	StringView(const char* begin, const char* end);
	StringView(const char* string);
	StringView(const String& string);//Class String from topic 9

	unsigned length() const;
	char operator[](unsigned index) const;

	StringView substr(unsigned from, unsigned length);

	friend std::ostream& operator<<(std::ostream& os, const StringView& view);
};
