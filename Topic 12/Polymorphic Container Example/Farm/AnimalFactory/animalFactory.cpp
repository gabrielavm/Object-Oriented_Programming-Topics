#include "animalFactory.h"
#include "../Animals/Cat.h"
#include "../Animals/Dog.h"
#include "../Animals/Cow.h"

Animal* animalFactory(AnimalType type)
{
	switch (type)
	{
	case AnimalType::Dog:
		return new Dog();

	case AnimalType::Cat:
		return new Cat();

	case AnimalType::Cow:
		return new Cow();

	default:
		throw std::exception("Invalid animal type!");
	}
}
