#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

void Triangle::intersectWith(const Shape& other) const
{
	return other.intersectWithTriangle(*this);
}

void Triangle::intersectWithCircle(const Circle& other) const
{
	std::cout << "Formula for triangle and circle" << std::endl;
}

void Triangle::intersectWithTriangle(const Triangle& other) const
{
	std::cout << "Formula for triangle and triangle" << std::endl;
}

void Triangle::intersectWithRectangle(const Rectangle& other) const
{
	std::cout << "Formula for triangle and rectangle" << std::endl;
}
