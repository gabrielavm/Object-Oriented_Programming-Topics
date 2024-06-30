#pragma once
#include <iostream>
#pragma warning (disable : 4996)

class Student
{
	char* name = nullptr;
	double* grades = nullptr;
	size_t gradesCount = 0;

	void copyName(const char* name);
	void copyGrades(const double* grades, size_t gradesCount);

	void free();
	void copyFrom(const Student& other);

public:

	Student(const char* name, const double* grades, size_t gradesCount);

	//Big 4
	Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setName(const char* name);
	void setGrades(const double* grades, size_t gradesCount);

	const char* getName() const;
	const double* getGrades() const;

	size_t getGradesCount() const;
};
