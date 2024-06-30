#include "Cow.h"

Cow::Cow() : Animal(AnimalType::Cow)
{}

void Cow::roar() const
{
	std::cout << "Muu Muu" << std::endl;
}

Animal* Cow::clone() const
{
	return new Cow(*this);
}
