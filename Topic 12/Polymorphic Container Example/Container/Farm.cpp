#include "Farm.h"
#include "../Factory/AnimalFactory.h"

void Farm::free()
{
	for (int i = 0; i < animalsCount; i++)
	{
		delete animals[i];
	}
	delete[] animals;

	animalsCount = 0;
	capacity = 0;
}

void Farm::copyFrom(const Farm& other)
{
	animals = new Animal * [other.capacity];
	for (int i = 0; i < animalsCount; i++)
	{
		animals[i] = other.animals[i]->clone();
	}

	animalsCount = other.animalsCount;
	capacity = other.capacity;
}

void Farm::moveFrom(Farm&& other)
{
	animals = other.animals;
	other.animals = nullptr;

	animalsCount = other.animalsCount;
	other.animalsCount = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void Farm::resize()
{
	Animal** animalsCopy = new Animal * [capacity *= 2];
	for (int i = 0; i < animalsCount; i++)
	{
		animalsCopy[i] = animals[i];
	}

	delete[] animals;
	animals = animalsCopy;
}

Farm::Farm()
{
	capacity = 8;
	animalsCount = 0;
	animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Farm::~Farm()
{
	free();
}

void Farm::addAnimal(const Animal& animal)
{
	if (animalsCount == capacity)
	{
		resize();
	}

	animals[animalsCount] = animal.clone();
	++animalsCount;
}

void Farm::addAnimal(Animal&& animal) noexcept
{
	if (animalsCount == capacity)
	{
		resize();
	}

	animals[animalsCount] = std::move(&animal);
	++animalsCount;
}

void Farm::addAnimal(AnimalType type)
{
	if (animalsCount == capacity)
	{
		resize();
	}

	animals[animalsCount] = animalFactory(type);
	++animalsCount;
}

void Farm::roarAll() const
{
	for (int i = 0; i < animalsCount; i++)
	{
		animals[i]->roar();
	}
}

AnimalType Farm::getTypeAtIndex(size_t index) const
{
	if (index > animalsCount)
	{
		throw std::exception("Invalid index!");
	}

	return animals[index]->getType();
}
