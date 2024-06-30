#pragma once
#include <iostream>
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:

	Circle(int x, int y, double radius);

	double getPerimeter() const override;
	double getArea() const override;
	bool isPointInShape(int x, int y) const override;
};
