#include "Complex.h"

Complex::Complex() : Im(0), Re(0)
{}

Complex::Complex(double Re, double Im) : Im(Im), Re(Re)
{}

void Complex::setRe(double Re)
{
	this->Re = Re;
}

void Complex::setIm(double Im)
{
	this->Im = Im;
}

double Complex::getRe() const
{
	return Re;
}

double Complex::getIm() const
{
	return Im;
}

Complex Complex::getConjugated() const
{
	Complex result(*this);
	result.Im += (-1);

	return result;
}

Complex& Complex::operator+=(const Complex& other)
{
	this->Re += other.Re;
	this->Im += other.Im;

	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	this->Re -= other.Re;
	this->Im -= other.Im;

	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double ReCopy = this->Re;

	//z1, z2 - complex numbers
	//z1 * z2 = (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
	this->Re = ((ReCopy * other.Re) - (Im * other.Im));//(ac - bd)
	this-> Im = ((ReCopy * other.Im) + (Im * other.Re));//(ad + bc)i

	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	double ReCopy = this->Re;

	//z1, z2 - complex numbers
	
	//z1 = (a + bi) = (a + bi) * (c - di) = (ac + bd)   + (cb - ad)i
	//z2   (c + di)   (c + di)   (c - di)   (c^2 + d^2)   (c^2 + d^2)

	this->Re = (((ReCopy * other.Re) + (this->Im * other.Im)) /
				((other.Re * other.Re) + (other.Im * other.Im)));// (ac + bd) / (c^2 + d^2)

	this->Im = (((other.Re * this->Im) - (ReCopy * other.Im)) /
				((other.Re * other.Re) + (other.Im * other.Im)));// (cb - ad)i / (c^2 + d^2)

	return *this;
}

//Implementation of "operator/= from lectures"
/*
Complex& Complex::operator/=(const Complex& other) // a/=b
{
	Complex Conjugated = other.getConjugated(); //we take the complex conjugate of the other fraction (b)

	Complex otherCopy(other); //we copy the other (b) so as not to change it.

	//We multiply the two by the complex conjugate.
	*this *= Conjugated;
	otherCopy *= Conjugated;

	if (otherCopy.Re != 0)
	{
		Re /= otherCopy.Re;
		Im /= otherCopy.Re;
	}

	return *this;
}
*/

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	return os << complex.Re << " + " << complex.Im << "i ";
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
	return is >> complex.Re >> complex.Im;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result += rhs;

	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result -= rhs;

	return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result *= rhs;

	return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result /= rhs;

	return result;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return ((lhs.getIm() == rhs.getIm()) && (lhs.getRe() == rhs.getRe()));
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}
