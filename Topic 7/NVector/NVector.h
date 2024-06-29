#pragma once
#include <iostream>
#include <fstream>

class NVector
{
	int* data;
	size_t size;

	void free();
	void copyFrom(const NVector& other);

public:

	NVector(size_t size);

	NVector(const NVector& other);
	NVector& operator=(const NVector& other);

	~NVector();

	NVector& operator+=(const NVector& other);
	NVector& operator-=(const NVector& other);

	NVector& operator*=(size_t scalar);

	int& operator[](size_t index);//get and set
	int operator[](size_t index) const;//only get

	size_t operator~() const; //get size

	friend std::ostream& operator<<(std::ostream& os, const NVector& vector);
	friend std::istream& operator>>(std::istream& is, NVector& vector);
};

NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);

//commutative operator
NVector operator*(const NVector& vector, size_t scalar);
NVector operator*(size_t scalar, const NVector& vector);

//are parallel
bool operator||(const NVector& lhs, const NVector& rhs);

//scalar product
size_t operator%(const NVector& lhs, const NVector& rhs);

//are perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs);
