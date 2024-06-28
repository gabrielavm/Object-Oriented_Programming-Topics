#include <iostream>
#include <cstring>

namespace Constants
{
	constexpr int MAX_NAME_LEN = 20;
	constexpr int MIN_NAME_LEN = 2;
	constexpr int MIN_AGE = 5;
	constexpr int MAX_AGE = 90;
}

bool isSmallLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isCapitalLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool containsOnlySmallChars(const char* str)
{
	size_t len = strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		if (!isSmallLetter(str[i]))
		{
			return false;
		}
	}

	return true;
}

class Person
{
	char name[Constants::MAX_NAME_LEN + 1] = "Unknown";
	int age = Constants::MIN_AGE;

	bool isValidAge(int age)
	{
		return age >= Constants::MIN_AGE && age <= Constants::MAX_AGE;
	}

	bool isValidName(const char* name)
	{
		if (name == nullptr)
		{
			return false;
		}

		size_t nameLen = strlen(name);

		if (nameLen <= Constants::MIN_NAME_LEN || nameLen >= Constants::MAX_NAME_LEN)
		{
			return false;
		}

		if (!isCapitalLetter(*name))
		{
			return false;
		}

		return containsOnlySmallChars(name + 1);
	}

public:

	Person() = default;

	Person(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}

	int getAge() const
	{
		return age;
	}

	const char* getName() const
	{
		return name;
	}

	void setName(const char* name)
	{
		if (isValidName(name))
		{
			strcpy(this->name, name);
		}
		else
		{
			strcpy(this->name, "Unknown");
		}
	}

	void setAge(int age)
	{
		if (isValidAge(age))
		{
			this->age = age;
		}
		else
		{
			this->age = Constants::MIN_AGE;
		}
	}
};

int main()
{
	Person s("Example name", 33);
}
