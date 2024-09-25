#include "Board.h"

Board::Board() 
{
	// Initalizes all the positions of the board to 0
	memset(board, 0, sizeof(board));

	for (int i = 0; i < 20; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			boardShapes[i][j] = sf::RectangleShape(sf::Vector2f(20, 20));
			boardShapes[i][j].setPosition(j * 20, i * 20);
			boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(sf::Color(0, 0, 0));
		}
	}
}

void Board::UpdateBoardColors() 
{
	for (int i = 0; i < 20; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			switch (board[i][j])
			{
			case 0:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 1:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 2:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 3:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 4:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 5:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 6:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 7:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			}
		}
	}
}

void Board::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			rt.draw(boardShapes[i][j], rs);
		}
	}
}