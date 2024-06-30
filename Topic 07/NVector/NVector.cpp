#include "NVector.h"

void NVector::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

void NVector::copyFrom(const NVector& other)
{
	data = new int[other.size];
	for (int i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}

	size = other.size;
}

NVector::NVector(size_t size)
{
	data = new int[size] {0};
	this->size = size;
}

NVector::NVector(const NVector& other)
{
	copyFrom(other);
}

NVector& NVector::operator=(const NVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

NVector::~NVector()
{
	free();
}

NVector& NVector::operator+=(const NVector& other)
{
	if (size != other.size)
	{
		throw "The vectors must have the same size!";
	}

	for (int i = 0; i < size; i++)
	{
		data[i] += other.data[i];
	}

	return *this;
}

NVector& NVector::operator-=(const NVector& other)
{
	if (size != other.size)
	{
		throw "The vectors must have the same size!";
	}

	for (int i = 0; i < size; i++)
	{
		data[i] -= other.data[i];
	}

	return *this;
}

NVector& NVector::operator*=(size_t scalar)
{
	for (int i = 0; i < size; i++)
	{
		data[i] *= scalar;
	}

	return *this;
}

int& NVector::operator[](size_t index)//get and set
{
	if (index >= size)
	{
		throw "Invalid index!";
	}

	return data[index];
}

int NVector::operator[](size_t index) const//only get
{
	if (index >= size)
	{
		throw "Invalid index!";
	}

	return data[index];
}

size_t NVector::operator~() const//get size
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const NVector& vector)
{
	os << vector.size;

	for (int i = 0; i < vector.size; i++)
	{
		os << vector.data[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, NVector& vector)
{
	is >> vector.size;

	for (int i = 0; i < vector.size; i++)
	{
		is >> vector.data[i];
	}

	return is;
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result += rhs;

	return result;
}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result -= rhs;

	return result;
}

//commutative operator
NVector operator*(const NVector& vector, size_t scalar)
{
	NVector result(vector);
	result *= scalar;

	return result;
}

NVector operator*(size_t scalar, const NVector& vector)
{
	return (vector * scalar);
}

//are parallel
bool operator||(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs) 
	{
		throw "The vectors should have the same size!";
	}

	double ratio = 0.0;
	bool ratioSet = false;

	for (size_t i = 0; i < ~lhs; ++i)
	{
		// Skip if both components are zero
		if (lhs[i] == 0 && rhs[i] == 0)
		{
			continue;
		}

		// If one component is zero but the other is not, vectors are not parallel
		if (lhs[i] == 0 || rhs[i] == 0)
		{
			return false;
		}

		// Calculate the ratio of the current components
		double currentRatio = lhs[i] / rhs[i];

		// If the ratio is not set, set it. Otherwise, compare it with the current ratio
		if (!ratioSet)
		{
			ratio = currentRatio;
			ratioSet = true;
		}
		else if (std::abs(ratio - currentRatio) > 1e-6)
		{ // Use a small epsilon for floating point comparison
			// If the ratios are different, vectors are not parallel
			return false;
		}
	}

	return true;
}

//scalar product
size_t operator%(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs)
	{
		throw "The vectors should have the same size!";
	}

	size_t res = 0;
	for (int i = 0; i < ~lhs; i++)
	{
		res += lhs[i] * rhs[i];
	}

	return res;
}

//are perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs)
{
	return  lhs % rhs == 0; //the size check is done by %
}
