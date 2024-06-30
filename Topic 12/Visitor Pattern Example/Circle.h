#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:

	Circle(int x, int y, double radius);

	void intersectWith(const Shape& other) const override;

	void intersectWithCircle(const Circle& other) const override;
	void intersectWithTriangle(const Triangle& other) const override;
	void intersectWithRectangle(const Rectangle& other) const override;
};
