#include "Student.h"

void Student::copyName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Student::copyGrades(const double* grades, size_t gradesCount)
{
	if (!grades || this->grades == grades)
	{
		return;
	}

	this->grades = new double[gradesCount];

	for (int i = 0; i < gradesCount; i++)
	{
		this->grades[i] = grades[i];
	}

	this->gradesCount = gradesCount;
}

void Student::free()
{
	delete[] name;
	delete[] grades;
	gradesCount = 0;
}

void Student::copyFrom(const Student& other)
{
	copyName(other.name);
	copyGrades(other.grades, other.gradesCount);
}

Student::Student(const char* name, const double* grades, size_t gradesCount)
{
	setName(name);
	setGrades(grades, gradesCount);
}

Student::Student() = default;

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Student::~Student()
{
	free();
}

void Student::setName(const char* name)
{
	delete[] this->name;
	copyName(name);
}

void Student::setGrades(const double* grades, size_t gradesCount)
{
	delete[] this->grades;
	copyGrades(grades, gradesCount);
}

const char* Student::getName() const
{
	return this->name;
}

const double* Student::getGrades() const
{
	return this->grades;
}

size_t Student::getGradesCount() const
{
	return this->gradesCount;
}
