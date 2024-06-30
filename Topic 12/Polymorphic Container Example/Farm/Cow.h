#pragma once
#include "Animal.h"

class Cow : public Animal
{
	Cow();

	void roar() const override;
	Animal* clone() const override;
};
