#include "Shape.h"

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

Shape::Shape(Shape&& other)
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

Shape& Shape::operator=(Shape&& other)
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
