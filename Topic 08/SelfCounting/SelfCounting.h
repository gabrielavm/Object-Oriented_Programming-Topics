#pragma once
#include <iostream>

class SelfCounting
{
	//individual for each object of this class
	const int value;

	//same for every object of this class
	static unsigned liveObjectsCount;
	static unsigned createdObjectsCount;

public:

	SelfCounting();
	SelfCounting(int value);
	SelfCounting(const SelfCounting& other);
	~SelfCounting();

	//the function gives the save output for each object of this class
	static unsigned getLiveObjectsCount();
	static unsigned getCreatedObjectsCount();
};
