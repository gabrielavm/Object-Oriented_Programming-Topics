#pragma once

class Shape
{
protected:

	struct Point
	{
		int x;
		int y;

		Point();
		Point(int x, int y);

		double getDist(const Point& other) const;
	};

	const Point& getPointAtIndex(size_t index) const;

private:

	Point* points;
	size_t pointsCount;

	void free();
	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);

public:

	Shape(size_t pointsCount);

	Shape(const Shape& other);
	Shape(Shape&& other) noexcept;

	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other) noexcept;

	virtual ~Shape();

	void setPoint(size_t pointIndex, int x, int y);

	virtual double getPerimeter() const;
	virtual double getArea() const = 0;

	virtual bool isPointInShape(int x, int y) const = 0;
};
