#pragma once
#include "Board.hpp"
#include "SnakeImpl.hpp"


class BoardImpl : public Board
{
public:
	void displayBoard(Position, Position, std::vector<Position>) override;
	std::vector<Position> getFrameComponentsPositions() const;
private:
	static constexpr uint16_t numberOfRows{ 25 }; //can it be static?
	static constexpr uint16_t numberOfColumns{ 30 }; //can it be static?
	std::array<std::array<BoardComponent, numberOfColumns>, numberOfRows> board{};  //{} initializes the array with zeros as default
	std::vector<Position> frameComponentsPositions; //can it be an array? cant board array be used instead somehow?
	SnakeImpl snake; //is it needed? only used for getting 8. cant it be an argument?
	FruitImpl fruit; //is it needed? only used for getting F. cant it be an argument?
	void displayHorizontalFramePart(uint8_t, uint16_t);
	void displayBoardComponent(uint16_t, uint16_t, uint8_t); //change first 2 arguments to Position?
};