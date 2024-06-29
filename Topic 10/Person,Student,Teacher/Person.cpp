#include "Person.h"

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;
}

void Person::moveFrom(Person&& other)
{
	name = other.name;
	other.name = nullptr;

	age = other.age;
	other.age = 0;
}

void Person::free()
{
	delete[] name;
	name = nullptr;
	age = 0;
}

Person::Person() = default;

Person::Person(const char* name, unsigned age)
{
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Person::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setAge(unsigned age)
{
	this->age = age;
}

const char* Person::getName() const
{
	return name;
}

unsigned Person::getAge() const
{
	return age;
}

void Person::printInfo() const
{
	std::cout << name << " , " << age << std::endl;
}

Person::~Person()
{
	free();
}
