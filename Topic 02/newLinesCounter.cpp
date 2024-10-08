#include <iostream>
#include <fstream>

const char NEW_LINE_CHAR = '\n';

int getCharCount(std::ifstream& ifs, char ch)
{
	if (!ifs.is_open())
	{
		return -1;
	}

	int count = 0;

	while (true)
	{
		char current = ifs.get();

		if (ifs.eof())
		{
			return count;
		}

		if (current == ch)
		{
			++count;
		}
	}

	return count;
}

int getNewLinesCount(const char* fileName)
{
	if (!fileName)
	{
		return -1;
	}

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return -1;
	}

	return (getCharCount(ifs, NEW_LINE_CHAR) + 1);
}
