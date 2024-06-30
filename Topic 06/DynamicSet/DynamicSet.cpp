#include "DynamicSet.h"

void DynamicSet::free()
{
	delete[] buckets;
	buckets = nullptr;

	bucketsCount = 0;
	N = 0;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
	buckets = new uint8_t[other.bucketsCount];
	for (unsigned i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}

	bucketsCount = other.bucketsCount;
	N = other.N;
}

unsigned DynamicSet::getBucketIndex(unsigned element) const
{
	return element / elementsInBucket;
}

unsigned DynamicSet::getBitIndex(unsigned element) const
{
	return element % elementsInBucket;
}

DynamicSet::DynamicSet(unsigned N)
{
	bucketsCount = N / elementsInBucket + 1;
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = N;
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

void DynamicSet::add(unsigned element)
{
	if (element > N)
	{
		return;
	}

	unsigned bucketIndex = getBucketIndex(element);
	unsigned bitIndex = getBitIndex(element);

	uint8_t mask = 1 << bitIndex;
	buckets[bucketIndex] |= mask;
}

void DynamicSet::remove(unsigned element)
{
	if (element > N)
	{
		return;
	}

	unsigned bucketIndex = getBucketIndex(element);
	unsigned bitIndex = getBitIndex(element);

	uint8_t mask = ~(1 << bitIndex);
	buckets[bucketIndex] &= mask;
}

bool DynamicSet::contains(unsigned element) const
{
	if (element > N)
	{
		return false;
	}

	unsigned bucketIndex = getBucketIndex(element);
	unsigned bitIndex = getBitIndex(element);
	uint8_t mask = 1 << bitIndex;

	return buckets[bucketIndex] & mask;
}

void DynamicSet::print() const
{
	std::cout << std::endl << "{ ";
	for (unsigned i = 0; i <= N; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << " }" << std::endl;
}

DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet unionResult(std::max(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (unsigned i = 0; i < minBucketsCount; i++)
	{
		unionResult.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}

	const DynamicSet& biggerSet = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;
	for (unsigned i = minBucketsCount; i < biggerSet.bucketsCount; i++)
	{
		unionResult.buckets[i] = biggerSet.buckets[i];
	}

	return unionResult;
}

DynamicSet intersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet intersectionResult(std::min(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (unsigned i = 0; i < minBucketsCount; i++)
	{
		intersectionResult.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}

	return intersectionResult;
}
