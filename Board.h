#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <cstring>
#include <vector>
#include <time.h>
#include "UserInterface.h"
#include "Tetromino.h"

// Header class of the board, that has the matrix for the board game, tetromino shapes, rectangle shape for the board.... 
class Board : public sf::Drawable 
{
private:
	Tetromino tetromino;

	int indexNewTetromino;
	int indexColorNewTetromino;

	sf::Color newTetrominoColor;

	std::vector<std::vector<bool>> nextTetrominoPiece; // Store the next tetromino shape
	sf::Color nextTetrominoColor; // Store the color of the next tetromino

	int coordX;
	int coordY;

	int timer = 0;
	int limitTimer = 30;

	int board[20][10];
	sf::RectangleShape boardShapes[20][10];
public:
	Board();
	bool GenerateTetromino();
	bool UpdateBoard();
	void UpdateBoardColors();
	void UpdateLimitTimer(int limitT);
	void RotateTetromino();
	void Right();
	void Left();
	int CheckLine();
	void ClearBoard();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};
