#include "SelfCounting.h"

unsigned SelfCounting::liveObjectsCount = 0;
unsigned SelfCounting::createdObjectsCount = 0;

SelfCounting::SelfCounting() : value(0)
{
	//we don't give a specific value to the object on creation,
	//so it may not increase the number of createdObjectsCount and liveObjectsCount
	
	//++createdObjectsCount;
	//++liveObjectsCount;
}

SelfCounting::SelfCounting(int value) : value(value)
{
	++createdObjectsCount;
	++liveObjectsCount;
}

SelfCounting::SelfCounting(const SelfCounting& other) : value(other.value)
{
	++createdObjectsCount;
	++liveObjectsCount;
}

SelfCounting::~SelfCounting()
{
	--liveObjectsCount;
}

unsigned SelfCounting::getLiveObjectsCount()
{
	return liveObjectsCount;
}

unsigned SelfCounting::getCreatedObjectsCount()
{
	return createdObjectsCount;
}
