#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}

void Rectangle::intersectWith(const Shape& other) const
{
	return other.intersectWithRectangle(*this);
}

void Rectangle::intersectWithCircle(const Circle& other) const
{
	std::cout << "Formula for rectangle and circle" << std::endl;
}

void Rectangle::intersectWithTriangle(const Triangle& other) const
{
	std::cout << "Formula for rectangle and triangle" << std::endl;
}

void Rectangle::intersectWithRectangle(const Rectangle& other) const
{
	std::cout << "Formula for rectangle and rectangle" << std::endl;
}
