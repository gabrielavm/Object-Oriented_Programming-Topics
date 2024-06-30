#include <iostream>
#include "DynamicSet.h"

int main()
{

	DynamicSet s1(1024);

	s1.add(1);
	s1.add(10);
	s1.add(5);
	s1.print();

	DynamicSet s2(1024);

	s2.add(1);
	s2.add(17);

	s1.add(130);
	s1.print();


	DynamicSet uni = unionOfSets(s1, s2);
	uni.print();

	DynamicSet intersect = intersectionOfSets(s1, s2);
	intersect.print();

	return 0;
}
