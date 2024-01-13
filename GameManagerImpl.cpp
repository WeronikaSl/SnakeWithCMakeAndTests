#include "GameManagerImpl.hpp"
#include <iostream>

GameManagerImpl GameManagerImpl::instance;

GameManagerImpl& GameManagerImpl::getInstance()
{
    return instance;
}

void GameManagerImpl::play()
{
    Position newSnakesHeadPosition{ snake.getPositionOfHead() };
    Position newFruitPosition{ fruit.getFruitPosition() };

    while (!isGameOver)
    {
        system("cls"); //shouldn't be used, but there's no other option for now
        newSnakesHeadPosition = convertUserImputToSnakesMovement();
        newFruitPosition = eatTheFruit(newSnakesHeadPosition);
        checkIfGameIsOver();
        board.displayBoard(newSnakesHeadPosition, newFruitPosition, snake.getTail().tailPositions);
        std::this_thread::sleep_for(400ms);
    }
    std::cout << std::endl << "Points: " << score << std::endl;
}

GameManagerImpl::GameManagerImpl()
{}

Position GameManagerImpl::convertUserImputToSnakesMovement()
{
    Direction currentSnakesMovementDirection = snake.getDirectionOfMovement();
    Direction newDirection = userInteractionHandler.convertUserInputToDirection(currentSnakesMovementDirection);
    snake.moveSnake(newDirection);
    return snake.getPositionOfHead();
}

Position GameManagerImpl::eatTheFruit(Position snakesHeadPosition)
{
    if (snakesHeadPosition == fruit.getFruitPosition())
    {
        fruit.setFruitPosition(fruit.generateFruitPosition());
        snake.growTail();
        score++;
    }
    return fruit.getFruitPosition();
}

void GameManagerImpl::checkIfGameIsOver()
{
    for (Position frameComponentPosition : board.getFrameComponentsPositions())
    {
        if (frameComponentPosition == snake.getPositionOfHead())
        {
            isGameOver = true;
        }
    }
    for (Position tailPosition : snake.getTail().tailPositions)
    {
        if (tailPosition == snake.getPositionOfHead())
        {
            isGameOver = true;
        }
    }
}
