#pragma once
#include <iostream>

class Person
{
	char* name = nullptr;
	unsigned age = 0;

	void copyFrom(const Person& other);
	void moveFrom(Person&& other);
	void free();

public:

	Person();
	Person(const char* name, unsigned age);

	Person(const Person& other);
	Person(Person&& other) noexcept;

	Person& operator=(const Person& other);
	Person& operator=(Person&& other) noexcept;

protected:

	void setName(const char* name);
	void setAge(unsigned age);

public:

	const char* getName() const;
	unsigned getAge() const;

	void printInfo() const;

	~Person();
};
