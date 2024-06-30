#include <iostream>
#include <assert.h>
#include "Shape.h"

Shape::Point::Point() : x(0), y(0)
{}

Shape::Point::Point(int x, int y) : x(x), y(y)
{}

double Shape::Point::getDist(const Point& other) const
{
	int dx = x - other.x;
	int dy = y - other.y;

	return sqrt(dx * dx + dy * dy);
}

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
	{
		throw std::exception("Invalid point Index!");
	}

	return points[index];
}

void Shape::free()
{
	delete[] points;
	points = nullptr;
	pointsCount = 0;
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];
	for (int i = 0; i < other.pointsCount; i++)
	{
		points[i] = other.points[i];
	}

	pointsCount = other.pointsCount;
}

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = nullptr;

	pointsCount = other.pointsCount;
	other.pointsCount = 0;
}

Shape::Shape(size_t pointsCount)
{
	this->pointsCount = pointsCount;
	points = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	points[pointIndex].x = x;
	points[pointIndex].y = y;
}

double Shape::getPerimeter() const
{
	assert(pointsCount >= 3);

	double perimeter = 0;
	for (int i = 0; i < pointsCount; i++)
	{
		perimeter += points[i].getDist(points[i + 1]);
	}
	perimeter += points[pointsCount - 1].getDist(points[0]);

	return perimeter;
}
