#pragma once
#include <iostream>
#include "../Person/Person.h"

class Teacher : public Person
{
	char** subjects = nullptr;
	size_t subjectsCount = 0;

	void free();
	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);

public:

	Teacher();
	Teacher(const char* name, unsigned age, const char* const* subjects, size_t subjectsCount);

	Teacher(const Teacher& other);
	Teacher(Teacher&& other) noexcept;

	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other) noexcept;

	~Teacher();
};
