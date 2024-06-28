#include <iostream>

namespace Points
{
	struct Point
	{
		int x = 0;
		int y = 0;
	};

	void inputPoint(Point& point)
	{
		std::cin >> point.x;
		std::cin >> point.y;
	}

	double getDist(const Point& firstPoint, const Point& secondPoint)
	{
		int dx = firstPoint.x - secondPoint.x;
		int dy = firstPoint.y - secondPoint.y;

		return sqrt(dx * dx + dy * dy);
	}

	void printPoint(const Point& point)
	{
		std::cout << "( " << point.x << " , " << point.y << " )" << std::endl;
	}
}

namespace Figures
{
	using namespace Points;

	struct Triangle
	{
		Point p1;
		Point p2;
		Point p3;
	};

	void inputTriangle(Triangle& triangle)
	{
		inputPoint(triangle.p1);
		inputPoint(triangle.p2);
		inputPoint(triangle.p3);
	}

	double getArea(const Triangle& triangle)
	{
		double AB = getDist(triangle.p1, triangle.p2);
		double BC = getDist(triangle.p2, triangle.p3);
		double CA = getDist(triangle.p3, triangle.p1);

		double halfPer = (AB + BC + CA) / 2;

		return sqrt(halfPer * (halfPer - AB) * (halfPer - BC) * (halfPer - CA));
	}

	void sortTrianglesByArea(Triangle* triangles, size_t count)
	{
		double* areas = new double[count];
		for (int i = 0; i < count; i++)
		{
			areas[i] = getArea(triangles[i]);
		}

		for (int i = 0; i < count - 1; i++)
		{
			int minTriangleAreaIndex = i;

			for (int j = i + 1; j < count; j++)
			{
				if (areas[j] < areas[minTriangleAreaIndex])
				{
					minTriangleAreaIndex = j;
				}
			}

			if (minTriangleAreaIndex != i)
			{
				std::swap(areas[minTriangleAreaIndex], areas[i]);
				std::swap(triangles[minTriangleAreaIndex], triangles[i]);
			}
		}
		delete[] areas;
	}

	void printTriangle(const Triangle& triangle)
	{
		printPoint(triangle.p1);
		printPoint(triangle.p2);
		printPoint(triangle.p3);
		std::cout << std::endl;
	}
}

int main()
{
	size_t count;
	std::cin >> count;

	Figures::Triangle* triangleArr = new Figures::Triangle[count];

	for (size_t i = 0; i < count; i++)
	{
		Figures::inputTriangle(triangleArr[i]);
	}

	Figures::sortTrianglesByArea(triangleArr, count);

	for (size_t i = 0; i < count; i++)
	{
		Figures::printTriangle(triangleArr[i]);
	}

	delete[] triangleArr;
}
