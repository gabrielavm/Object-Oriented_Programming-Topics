#pragma once
#include <iostream>
#include "StringPool.h"

class ImmutableString
{
	const char* _data;
	size_t _length;
	static StringPool _pool;

	void copyFrom(const ImmutableString& data);
	void free();

public:

	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other) = delete; //this could be implemented in some cases
	~ImmutableString();

	size_t length() const;
	char operator[](size_t index) const;
	const char* c_str() const;
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
