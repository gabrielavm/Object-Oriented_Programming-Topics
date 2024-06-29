#include <iostream>
#include <fstream>

const int MAX_BUFFER_SIZE = 1024;

void selfPrint(std::ifstream& ifs)
{
	while (!ifs.eof())
	{
		char buffer[MAX_BUFFER_SIZE];
		ifs.getline(buffer, MAX_BUFFER_SIZE);

		std::cout << buffer << std::endl;
	}
}

int main()
{
	std::ifstream ifs("selfPrinting.cpp");
	if (!ifs.is_open())
	{
		std::cout << "Тhe file cannot be opened!";
		return -1;
	}

	selfPrint(ifs);

	return 0;
}
