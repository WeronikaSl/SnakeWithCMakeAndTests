#include "SnakeImpl.hpp"
#include <iostream>

void SnakeImpl::moveSnake(Direction direction)
{
	directionOfMovement = direction;
	switch (direction)
	{
	case Direction::UP: //create methods for this switch, code copied
		setTailPositions();
		tail.tailPositions[0] = positionOfHead; //beggining of tail has to always appear where head was before
		positionOfHead[0]--;

		break;
	case Direction::DOWN:
		setTailPositions();
		tail.tailPositions[0] = positionOfHead;
		positionOfHead[0]++;

		break;
	case Direction::LEFT:
		setTailPositions();
		tail.tailPositions[0] = positionOfHead;
		positionOfHead[1]--;

		break;
	case Direction::RIGHT:
		setTailPositions();
		tail.tailPositions[0] = positionOfHead;
		positionOfHead[1]++;

		break;
	default:
		break;
	}
}

uint8_t SnakeImpl::getSnakesHead() const
{
	return head;
}

Position SnakeImpl::getPositionOfHead() const
{
	return positionOfHead;
}

Direction SnakeImpl::getDirectionOfMovement() const
{
	return directionOfMovement;
}

SnakeImpl::Tail SnakeImpl::getTail() const
{
	return tail;
}

void SnakeImpl::growTail()
{
	tail.lengthOfTail++;
}

void SnakeImpl::setTailPositions()
{
	tail.tailPositions.resize(tail.lengthOfTail);
	for (uint16_t i = 1; i < tail.lengthOfTail; i++) //starts with 1 because beginning of tail already has Position
	{
		tail.tailPositions[tail.lengthOfTail - i] = (tail.tailPositions[tail.lengthOfTail - i - 1]);
	}
}


