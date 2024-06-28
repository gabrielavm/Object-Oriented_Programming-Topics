#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)

struct Student
{
	char* name;
	int age;
	int facultyNum;
};

Student initStudent(const char* name, int age, int facultyNum)
{
	Student newStudent;

	newStudent.name = new char[strlen(name) + 1];
	strcpy(newStudent.name, name);

	newStudent.age = age;
	newStudent.facultyNum = facultyNum;

	return newStudent;
}

void freeMemoryForStudent(Student& student)
{
	delete[] student.name;
	student.age = 0;
	student.facultyNum = 0;
}

void saveStudentToBinaryFile(const Student& student, std::ofstream& ofs)
{
	size_t nameSize = strlen(student.name);
	ofs.write((const char*)&nameSize, sizeof(nameSize));
	ofs.write(student.name, nameSize + 1);

	ofs.write((const char*)&student.age, sizeof(student.age));
	ofs.write((const char*)&student.facultyNum, sizeof(student.facultyNum));
}

Student readStudentFromBinaryFile(std::ifstream& ifs) 
{
	Student student;

	size_t nameSize;
	ifs.read((char*)&nameSize, sizeof(nameSize));

	student.name = new char[nameSize + 1];
	ifs.read(student.name, nameSize + 1);

	ifs.read((char*)&student.age, sizeof(student.age));
	ifs.read((char*)&student.facultyNum, sizeof(student.facultyNum));

	return student;
}

void printStudentInfo(const Student& student)
{
	std::cout << student.name << " , " 
		<< student.age << " , " 
		<< student.facultyNum 
		<< std::endl;
}

void saveStudentsArrayToFile(const Student* students, size_t count, std::ofstream& ofs)
{
	ofs.write((const char*)&count, sizeof(count));

	for (int i = 0; i < count; i++)
	{
		saveStudentToBinaryFile(students[i], ofs);
	}
}

void readStudentsArrayFromFile(Student*& students, size_t& count, std::ifstream& ifs)
{
	ifs.read((char*)&count, sizeof(count));

	students = new Student[count];

	for (int i = 0; i < count; i++)
	{
		students[i] = readStudentFromBinaryFile(ifs);
	}
}

int main()
{
	//TEST 1
	{
		std::ofstream ofs("arrStudents.dat", std::ios::out | std::ios::binary);

		if (!ofs.is_open())
		{
			return -1;
		}

		Student arr[3];

		arr[0] = initStudent("Ivan", 10, 20);
		arr[1] = initStudent("Peter", 41, 44);
		arr[2] = initStudent("Nikolay", 99, 0);

		saveStudentsArrayToFile(arr, 3, ofs);

		freeMemoryForStudent(arr[0]);
		freeMemoryForStudent(arr[1]);
		freeMemoryForStudent(arr[2]);
	}


	//TEST 2
	{
		std::ifstream ifs("arrStudents.dat", std::ios::in | std::ios::binary);
		if (!ifs.is_open())
		{
			return -1;
		}

		Student* arr;
		size_t size;

		readStudentsArrayFromFile(arr, size, ifs);

		for (size_t i = 0; i < size; i++)
		{
			printStudentInfo(arr[i]);
		}

		for (size_t i = 0; i < size; i++)
		{
			freeMemoryForStudent(arr[i]);
		}
	}
}
