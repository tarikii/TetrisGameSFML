#include <iostream>
#include "SFML/Graphics.hpp"
#include <cstring>
#include <vector>
#include <time.h>
#include "Tetromino.h"

class Board : public sf::Drawable 
{
private:
	Tetromino tetromino;

	int indexNewTetromino;
	int indexColorNewTetromino;

	sf::Color newTetrominoColor;

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
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};
