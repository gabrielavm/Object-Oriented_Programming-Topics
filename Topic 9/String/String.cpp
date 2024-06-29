#include "String.h"

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
	return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

void String::free()
{
	delete[] data;
	data = nullptr;

	length = 0;
	allocatedDataLength = 0;
}

void String::copyFrom(const String& other)
{
	data = new char[other.length + 1];
	strcpy(data, other.data);

	length = other.length;
	allocatedDataLength = other.allocatedDataLength;
}

void String::moveFrom(String&& other)
{
	data = other.data;
	other.data = nullptr;

	length = other.length;
	other.length = 0;

	allocatedDataLength = other.allocatedDataLength;
	other.allocatedDataLength = 0;
}

void String::resize(size_t newAllocatedDataLen)
{
	char* dataCopy = new char[newAllocatedDataLen + 1];
	strcpy(dataCopy, data);

	delete[] data;
	data = dataCopy;

	allocatedDataLength = newAllocatedDataLen;
}

explicit String::String(size_t length)
{
	allocatedDataLength = dataToAllocByStringLen(length);
	data = new char[allocatedDataLength];
	this->length = 0;
	data[0] = '\0';
}

String::String() : String("")
{}

String::String(const char* data)
{
	length = strlen(data);
	allocatedDataLength = dataToAllocByStringLen(length);
	this->data = new char[allocatedDataLength];
	strcpy(this->data, data);
}

String::String(const String& other)
{
	copyFrom(other);
}

String::String(String&& other) noexcept
{
	moveFrom(std::move(other));
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

size_t String::getLength() const
{
	return length;
}

size_t String::getAllocatedDataLength() const
{
	return allocatedDataLength;
}

const char* String::c_str() const
{
	return data;
}

String& String::operator+=(const String& other)
{
	if (getLength() + other.getLength() + 1 > allocatedDataLength)
	{
		resize(dataToAllocByStringLen(getLength() + other.getLength()));
	}

	std::strncat(data, other.data, other.getLength());
	length = getLength() + other.getLength();

	return *this;
}

char& String::operator[](size_t index)
{
	return data[index];
}

const char& String::operator[](size_t index) const
{
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buff[MAX_BUFFER_SIZE];
	is >> buff;

	size_t buffStringSize = std::strlen(buff);

	if (buffStringSize > str.getAllocatedDataLength())
	{
		str.resize(dataToAllocByStringLen(buffStringSize));
	}

	strcpy(str.data, buff);
	str.length = buffStringSize;

	return is;
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs.length + rhs.length);
	result += lhs;
	result += rhs;

	return result;
}

String::~String()
{
	free();
}

bool operator==(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
