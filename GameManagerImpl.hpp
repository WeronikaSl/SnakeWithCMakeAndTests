#pragma once
#include "GameManager.hpp"
#include "UserInteractionHandlerImpl.hpp"
#include "BoardImpl.hpp"
#include <thread> 

using namespace std::chrono_literals;

class GameManagerImpl : public GameManager //change to Singleton to practice
{
public:
	GameManagerImpl(const GameManagerImpl&) = delete;
	static GameManagerImpl& getInstance();
	void play() override;
private:
	GameManagerImpl();
	static GameManagerImpl instance;
	UserInteractionHandlerImpl userInteractionHandler;
	BoardImpl board;
	FruitImpl fruit;
	SnakeImpl snake;
	bool isGameOver{ false };
	uint16_t score{ 0 };
	Position convertUserImputToSnakesMovement();
	Position eatTheFruit(Position);
	void checkIfGameIsOver();

};