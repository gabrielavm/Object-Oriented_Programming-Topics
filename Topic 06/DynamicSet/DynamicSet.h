#pragma once
#include <iostream>

class DynamicSet
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;

	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const DynamicSet& other);

	unsigned getBucketIndex(unsigned element) const;
	unsigned getBitIndex(unsigned element) const;

public:

	DynamicSet(unsigned N);

	DynamicSet(const DynamicSet& other);
	DynamicSet& operator=(const DynamicSet& other);

	~DynamicSet();

	void add(unsigned element);
	void remove(unsigned element);
	bool contains(unsigned element) const;
	void print() const;

	friend DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet intersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
};
