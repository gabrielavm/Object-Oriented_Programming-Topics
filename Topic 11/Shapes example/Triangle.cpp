#include "Triangle.h"
#include <limits>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

double Triangle::getArea() const
{
	//Heron's formula for area of triangle
	double AB = getPointAtIndex(0).getDist(getPointAtIndex(1));
	double BC = getPointAtIndex(1).getDist(getPointAtIndex(2));
	double CA = getPointAtIndex(2).getDist(getPointAtIndex(0));

	double halfPer = (AB + BC + CA) / 2;
	//double halfPer = getPerimeter() / 2; //alternatively

	return sqrt(halfPer * (halfPer - AB) * (halfPer - BC) * (halfPer - CA));
}

bool Triangle::isPointInShape(int x, int y) const
{
	Shape::Point p(x, y);
	Triangle t1(getPointAtIndex(0).x, getPointAtIndex(0).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y);
	Triangle t2(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y);
	Triangle t3(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(0).x, getPointAtIndex(0).y, p.x, p.y);

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();
}
