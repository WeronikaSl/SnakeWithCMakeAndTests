#pragma once
#include "Types.hpp"

class Fruit
{
public:
	virtual ~Fruit() {}
	virtual uint8_t getFruit() const = 0;
	virtual Position generateFruitPosition() const = 0;
};