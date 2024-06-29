#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewerFile
{
	unsigned char* data;
	size_t dataSize;
};

size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);

	return fileSize;
}

HexViewerFile initFile(const char* str)
{
	std::ifstream ifs(str, std::ios::in | std::ios::binary);

	HexViewerFile file;

	if (!ifs.is_open())
	{
		file.data = nullptr;
		file.dataSize = 0;

		return file;
	}

	file.dataSize = getFileSize(ifs);
	file.data = new unsigned char[file.dataSize];
	ifs.read((char*)file.data, file.dataSize);

	ifs.close();

	return file;
}

void freeHexViewerFile(HexViewerFile& file)
{
	delete[] file.data;
	file.dataSize = 0;
}

bool isValidSymbol(unsigned char ch)
{
	return ch >= 'a' && ch <= 'z' ||
		ch >= 'A' && ch <= 'Z' ||
		ch >= '0' && ch <= '9';
}

void printFileInfo(const HexViewerFile& myFile)
{
	for (int i = 0; i < myFile.dataSize; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)myFile.data[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < myFile.dataSize; i++)
	{
		if (isValidSymbol(myFile.data[i]))
		{
			std::cout << myFile.data[i] << "  ";
		}
		else
		{
			std::cout << ".. ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	HexViewerFile myFile = initFile("student.dat");
	printFileInfo(myFile);
	freeHexViewerFile(myFile);
}
