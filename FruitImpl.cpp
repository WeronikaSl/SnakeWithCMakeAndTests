#include "FruitImpl.hpp"
#include <iostream>
#include <random>

uint8_t FruitImpl::getFruit() const
{
	return fruit;
}

Position FruitImpl::generateFruitPosition() const
{
	std::random_device rd;
	std::uniform_int_distribution<uint16_t> dist(2, 23);  //depends on boardSize, shoule it be hardcoded? can i pass nr of rows and columns somehow?
	return { dist(rd) ,dist(rd) };
}

Position FruitImpl::getFruitPosition() const
{
	return fruitPosition;
}

void FruitImpl::setFruitPosition(Position newFruitPosition)
{
	fruitPosition = newFruitPosition;
}
