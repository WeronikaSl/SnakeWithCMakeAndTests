#pragma once
#include "Fruit.hpp"

class FruitImpl : public Fruit
{
public:
	uint8_t getFruit() const override;
	Position generateFruitPosition() const;
	Position getFruitPosition() const;
	void setFruitPosition(Position);

private:
	uint8_t fruit{ 'F' };
	Position fruitPosition{ 5,5 }; //random starting position for first fruit
};