#include "BoardImpl.hpp"
#include <iostream>
#include <array>
#include <algorithm>


void BoardImpl::displayBoard(Position snakesHeadPosition, Position fruitsPosition, std::vector<Position> tailPositions) //FIX SPAGHETTI CODE IN THIS METHOD
{
	constexpr std::array<BoardComponent, 2> boardComponents{ 'x', ' ' };
	constexpr std::array<uint16_t, 2> firstAndLastRowIndex{ 0, (numberOfRows - 1) };

	displayHorizontalFramePart(boardComponents[0], firstAndLastRowIndex[0]);

	std::cout << std::endl;

	for (uint16_t i{ 1 }; i < firstAndLastRowIndex[1]; i++) //can I use ranged based foor loop here somehow? //first and last row displayed in different methods
	{
		for (uint16_t k{ 0 }; k < numberOfColumns; k++)
		{
			if ((k == 0) || (k == (numberOfColumns - 1))) //-1 because starts with 0, not with 1
			{
				displayBoardComponent(i, k, boardComponents[0]);
				frameComponentsPositions.push_back(Position{ i, k });  //how to use emplace back here?
			}
			else if (i == snakesHeadPosition[0] && k == snakesHeadPosition[1])
			{
				displayBoardComponent(i, k, snake.getSnakesHead());
			}
			else if (i == fruitsPosition[0] && k == fruitsPosition[1])
			{
				displayBoardComponent(i, k, fruit.getFruit());
			}
			else
			{
				if (auto isValue = std::find(tailPositions.begin(), tailPositions.end(), Position{ i,k }); isValue != tailPositions.end())
				{
					displayBoardComponent(i, k, snake.getTail().tailComponent);
				}
				else
				{
					displayBoardComponent(i, k, boardComponents[1]);
				}
			}
		}
		std::cout << std::endl;
	}

	displayHorizontalFramePart(boardComponents[0], firstAndLastRowIndex[1]);

	//for (std::array<BoardComponent, numberOfColumns> rows : board) //added for testing purpouses
	//{
	//	for (BoardComponent component : rows)
	//	{
	//		std::cout << component;
	//	}
	//	std::cout << std::endl;
	//}

}

std::vector<Position> BoardImpl::getFrameComponentsPositions() const
{
	return frameComponentsPositions;
}

void BoardImpl::displayHorizontalFramePart(uint8_t boardComponent, uint16_t row)
{
	for (uint16_t i{ 0 }; i < numberOfColumns; i++)
	{
		frameComponentsPositions.push_back(Position{ row, i }); //how to use emplace back here?
		displayBoardComponent(row, i, boardComponent);
	}
}

void BoardImpl::displayBoardComponent(uint16_t rowNumber, uint16_t columnNumber, uint8_t boardComponent)
{
	board[rowNumber][columnNumber] = boardComponent;
	std::cout << board[rowNumber][columnNumber];
}

