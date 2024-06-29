#pragma once
#include <iostream>
#include <fstream>

class Complex
{
	double Re;
	double Im;

public:

	Complex();
	Complex(double Re, double Im);

	void setRe(double Re);
	void setIm(double Im);

	double getRe() const;
	double getIm() const;

	Complex getConjugated() const;

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
	friend std::istream& operator>>(std::istream& is, Complex& complex);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
