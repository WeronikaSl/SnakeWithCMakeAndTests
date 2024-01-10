#pragma once
#include "Snake.hpp"
#include <vector>

class SnakeImpl : public Snake
{
public:
	struct Tail
	{
		std::vector<Position> tailPositions{ {4,5} }; //random starting position for beginning of tail
		Length lengthOfTail{ 1 };
		uint8_t tailComponent{ 'o' };
	};
	void moveSnake(Direction);
	uint8_t getSnakesHead() const;
	Position getPositionOfHead() const;
	Direction getDirectionOfMovement() const;
	Tail getTail() const;
	void growTail();

private:
	Position positionOfHead{ 5,5 }; //random starting position for beginning of tail
	Tail tail;
	Direction directionOfMovement{ Direction::DOWN };
	uint8_t head{ '8' };
	void setTailPositions();
};