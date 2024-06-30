#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}

double Rectangle::getArea() const
{
	double length = getPointAtIndex(0).getDist(getPointAtIndex(1));
	double width = getPointAtIndex(0).getDist(getPointAtIndex(3));

	return length * width;
}

bool Rectangle::isPointInShape(int x, int y) const
{
	Shape::Point point(x, y);

	return point.x >= getPointAtIndex(0).x && point.x <= getPointAtIndex(2).x &&
			point.y <= getPointAtIndex(0).y && point.y >= getPointAtIndex(2).y;
}
