#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shape(1)
{
	setPoint(0, x, y);
	this->radius = radius;
}

void Circle::intersectWith(const Shape& other) const
{
	return other.intersectWithCircle(*this);
}

void Circle::intersectWithCircle(const Circle& other) const
{
	std::cout << "Formula for circle and circle" << std::endl;
}

void Circle::intersectWithTriangle(const Triangle& other) const
{
	std::cout << "Formula for circle and triangle" << std::endl;
}

void Circle::intersectWithRectangle(const Rectangle& other) const
{
	std::cout << "Formula for circle and rectangle" << std::endl;
}
