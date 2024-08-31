#include "StringView.h"

StringView::StringView(const char* begin, const char* end) : begin(begin), end(end)
{}

StringView::StringView(const char* string) : StringView(string, string + strlen(string))
{}

StringView::StringView(const String& string) : StringView(string.c_str())
{}

unsigned StringView::length() const
{
	return end - begin;
}

char StringView::operator[](unsigned index) const
{
	return begin[index];
}

StringView StringView::substr(unsigned from, unsigned length)
{
	if (begin + from + length > end)
	{
		throw std::out_of_range("ERROR!");
	}

	return StringView(begin + from, begin + from + length);
}

std::ostream& operator<<(std::ostream& os, const StringView& view)
{
	const char* iter = view.begin;

	while (iter != view.end)
	{
		os << *iter;
		++iter;
	}

	return os;
}
