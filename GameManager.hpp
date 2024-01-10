#pragma once
#include "Types.hpp"

class GameManager
{
public:
	virtual ~GameManager() {};
	virtual void play() = 0;
};