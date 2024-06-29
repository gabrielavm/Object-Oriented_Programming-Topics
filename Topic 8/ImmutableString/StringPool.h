#pragma once

class StringPool
{
	struct StringRecord
	{
		char* str = nullptr;
		unsigned refCount = 0;
	};

	StringRecord* stringRecords;
	size_t stringCount = 0;
	size_t stringCapacity = 0;

	void resize(unsigned newCap);

	unsigned allocatedNewString(const char* str);
	int findAllocatedString(const char* str) const;

	void removeRecord(unsigned index);

public:

	StringPool();

	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);

	StringPool(const StringPool&) = delete;
	StringPool& operator=(const StringPool&) = delete;

	~StringPool();
};
