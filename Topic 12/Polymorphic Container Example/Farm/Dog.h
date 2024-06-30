#pragma once
#include "Animal.h"

class Dog : public Animal
{
	Dog();

	void roar() const override;
	Animal* clone() const override;
};
