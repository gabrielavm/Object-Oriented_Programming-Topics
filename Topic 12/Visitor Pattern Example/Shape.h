#pragma once
#include <iostream>

class Circle;
class Triangle;
class Rectangle;

class Shape
{
protected:

	struct Point
	{
		int x;
		int y;

		Point() : x(0), y(0) {}
		Point(int x, int y) : x(x), y(y) {}

		double getDist(const Point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};

private:

	Point* points;
	size_t pointsCount;

	void free();
	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);

public:

	Shape(size_t pointsCount);

	Shape(const Shape& other);
	Shape(Shape&& other);

	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other);

	virtual ~Shape();

	virtual void intersectWith() const = 0;

	virtual void intersectWithCircle(const Circle& other) const = 0;
	virtual void intersectWithTriangle(const Triangle& other) const = 0;
	virtual void intersectWithRectangle(const Rectangle& other) const = 0;
};
