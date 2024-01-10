#include "UserInteractionHandlerImpl.hpp"
#pragma warning(disable : 4996) //disabled to use conio.h

Direction UserInteractionHandlerImpl::convertUserInputToDirection(Direction currentDirection)
{
    uint8_t userInput{ takeInputFromUser() }; //create type UserInput?
    Direction direction{ currentDirection }; //if user won't click anything, snake moves in the same direction as before
    switch (userInput)
    {
    case 'w':
        if (currentDirection != Direction::DOWN)
        {
            direction = Direction::UP;
        }
        break;
    case 'a':
        if (currentDirection != Direction::RIGHT)
        {
            direction = Direction::LEFT;
        }
        break;
    case 's':
        if (currentDirection != Direction::UP)
        {
            direction = Direction::DOWN;
        }
        break;
    case 'd':
        if (currentDirection != Direction::LEFT)
        {
            direction = Direction::RIGHT;
        }
        break;
    default:
        break;
    }
    return direction;
}

uint8_t UserInteractionHandlerImpl::takeInputFromUser() const
{
    if (kbhit()) //shouldn't be used, but there's no other option for now
    {
        return getch(); //shouldn't be used, but there's no other option for now
    }
    else
    {
        return 'x'; //random value just to remove warning
    }
}
