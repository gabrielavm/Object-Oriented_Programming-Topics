#pragma once
#include <iostream>
#include "../Person/Person.h"

class Student : public Person
{
	unsigned facultyNum = 0;

public:

	Student();
	Student(const char* name, unsigned age, unsigned facultyNum);

	void setFacultyNum(unsigned facultyNum);
	unsigned getFacultyNum() const;
};
