#pragma once
#include "Types.hpp"
#include "FruitImpl.hpp"
#include "UserInteractionHandlerImpl.hpp"

class Board
{
public:
	virtual ~Board() {}
	virtual void displayBoard(Position, Position, std::vector<Position>) = 0;
};