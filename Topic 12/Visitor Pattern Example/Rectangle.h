#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:

	Rectangle(int x1, int y1, int x3, int y3);

	void intersectWith(const Shape& other) const override;

	void intersectWithCircle(const Circle& other) const override;
	void intersectWithTriangle(const Triangle& other) const override;
	void intersectWithRectangle(const Rectangle& other) const override;
};
