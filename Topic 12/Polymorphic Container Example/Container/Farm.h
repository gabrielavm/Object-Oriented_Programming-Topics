#pragma once
#include "../Animals/Animal.h"

class Farm
{
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void free();
	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void resize();

public:

	Farm();

	Farm(const Farm& other);
	Farm(Farm&& other) noexcept;

	Farm& operator=(const Farm& other);
	Farm& operator=(Farm&& other) noexcept;

	~Farm();

	void addAnimal(const Animal& animal);
	void addAnimal(Animal&& animal) noexcept;
	void addAnimal(AnimalType type);

	void roarAll() const;

	AnimalType getTypeAtIndex(size_t index) const;
};
