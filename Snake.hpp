#pragma once
#include "Types.hpp"

class Snake
{
public:
	virtual ~Snake() {}
	virtual void moveSnake(Direction) = 0;
	virtual uint8_t getSnakesHead() const = 0;
};