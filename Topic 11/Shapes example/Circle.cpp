#include <iostream>
#include "Circle.h"

constexpr double PI = 3.14;

Circle::Circle(int x, int y, double radius) : Shape(1)
{
	setPoint(0, x, y);
	this->radius = radius;
}

double Circle::getPerimeter() const
{
	return 2 * PI * radius;
}

double Circle::getArea() const
{
	return PI * radius * radius;
}

bool Circle::isPointInShape(int x, int y) const
{
	Shape::Point point(x, y);
	double distance = point.getDist(getPointAtIndex(0));

	return distance <= radius;
}
