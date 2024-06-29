#include "Student.h"

Student::Student() = default;

Student::Student(const char* name, unsigned age, unsigned facultyNum) : Person(name, age)
{
	setFacultyNum(facultyNum);
}

void Student::setFacultyNum(unsigned facultyNum)
{
	this->facultyNum = facultyNum;
}

unsigned Student::getFacultyNum() const
{
	return facultyNum;
}
