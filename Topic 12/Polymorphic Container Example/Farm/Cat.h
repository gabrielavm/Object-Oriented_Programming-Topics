#pragma once
#include "Animal.h"

class Cat : public Animal
{
	Cat();

	void roar() const override;
	Animal* clone() const override;
};
