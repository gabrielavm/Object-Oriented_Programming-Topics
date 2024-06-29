#include <iostream>
#include "SelfCounting.h"

int main()
{
	SelfCounting s(4);
	SelfCounting s2(30);

	{
		SelfCounting s3(232);

		std::cout << SelfCounting::getCreatedObjectsCount() << " " << SelfCounting::getLiveObjectsCount() << std::endl;
	}

	std::cout << SelfCounting::getCreatedObjectsCount() << " " << SelfCounting::getLiveObjectsCount() << std::endl;
}
