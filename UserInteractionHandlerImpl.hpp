#pragma once
#include "UserInteractionHandler.hpp"
#include "SnakeImpl.hpp"
#include "Types.hpp"
#include <conio.h>

class UserInteractionHandlerImpl : public UserInteractionHandler
{
public:
	Direction convertUserInputToDirection(Direction);
private:
	uint8_t takeInputFromUser() const;
};