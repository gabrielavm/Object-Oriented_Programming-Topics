#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable : 4996)

constexpr int MAX_BUFFER_SIZE = 1024;

class String
{
	char* data;
	size_t length;
	size_t allocatedDataLength;

	void free();
	void copyFrom(const String& other);
	void moveFrom(String&& other);

	void resize(size_t newAllocatedDataLen);

	explicit String(size_t length);

public:

	String();
	String(const char* data);

	String(const String& other);
	String(String&& other) noexcept;

	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;

	size_t getLength() const;
	size_t getAllocatedDataLength() const;

	const char* c_str() const;

	String& operator+=(const String& other);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
	friend String operator+(const String& lhs, const String& rhs);

	~String();
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
