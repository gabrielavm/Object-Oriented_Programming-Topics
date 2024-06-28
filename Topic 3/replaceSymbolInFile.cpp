#include <iostream>
#include <fstream>

void replaceSymbolInFile(char toReplace, char replacement, std::fstream& stream)
{
	while (!stream.eof())
	{
		char currentSymbol = stream.get();

		if (currentSymbol != toReplace)
		{
			continue;
		}

		stream.seekp(-1, std::ios::cur);//return to the symbol that we want to replace
		stream.put(replacement);
		stream.flush();
	}
}

int main()
{
	std::fstream st("test.txt");

	if (!st.is_open())
	{
		std::cout << "ERROR! The file cannot be opened!";
		return -1;
	}

	replaceSymbolInFile('a', '&', st);

	st.close();
}
