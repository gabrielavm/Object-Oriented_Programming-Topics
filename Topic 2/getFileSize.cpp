#include <iostream>
#include <fstream>

int getFileSize(std::ifstream& ifs)
{
	int currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	int fileSize = ifs.tellg();
	ifs.seekg(currentPos, std::ios::beg);

	return fileSize;
}

int main()
{
	std::ifstream ifs("test.txt");
	if (!ifs.is_open())
	{
		std::cout << "Тhe file cannot be opened!";
		return -1;
	}

	std::cout << getFileSize(ifs);

	return 0;
}
