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

bool Board::GenerateTetromino()
{
	srand(time(NULL));
	indexNewTetromino = rand() % 7;

	std::vector<std::vector<bool>> tetrominoPiece = tetromino.ConsultTetromino(indexNewTetromino);

	int size = (int)tetrominoPiece.size();

	// Ensure the tetromino fits in the middle of the board
	coordY = 0;
	coordX = 5 - size / 2;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// Check if j + coordX is within bounds before accessing the tetrominoPiece
			if (j + coordX >= 0 && j + coordX < 10 && tetrominoPiece[i][j])
			{
				// Check if the board is already occupied at this position
				if (board[i][j + coordX] > 0)
					return false;

				// Place the tetromino piece (-1 indicates temporary position for new tetromino)
				board[i][j + coordX] = -1;
			}
		}
	}

	int color = 1 + rand() % 7;
	indexColorNewTetromino = color;

	switch (color)
	{
	case 1:
		newTetrominoColor = sf::Color(255, 166, 0);   // Orange
		break;
	case 2:
		newTetrominoColor = sf::Color(245, 152, 245); // Pink
		break;
	case 3:
		newTetrominoColor = sf::Color(51, 202, 153);  // Green
		break;
	case 4:
		newTetrominoColor = sf::Color(255, 110, 110); // Red
		break;
	case 5:
		newTetrominoColor = sf::Color(255, 202, 77);  // Yellow
		break;
	case 6:
		newTetrominoColor = sf::Color(166, 166, 255); // Blue
		break;
	case 7:
		newTetrominoColor = sf::Color(133, 194, 247); // Light Blue
		break;
	}

	return true;
}

bool Board::UpdateBoard() 
{
	bool limit = 0;
	int counter = 0;

	if (timer >= limitTimer) 
	{
		counter = 0;
		for (int i = 18; i >= 0; i--) 
		{
			for (int j = 0; j < 10; j++) 
			{
				if (board[i][j] == -1) 
				{
					if (board[i + 1][j] <= 0)
						counter++;
				}
			}
		}

		if (counter == 4) 
		{
			coordY++;
			for (int i = 18; i >= 0; i--)
			{
				for (int j = 0; j < 10; j++)
				{
					if (board[i][j] == -1)
					{
						board[i][j] = 0;
						board[i + 1][j] = -1;
					}
				}
			}
		}
		else
		{
			for (int i = 19; i >= 0; i--)
			{
				for (int j = 0; j < 10; j++)
				{
					if (board[i][j] == -1)
						board[i][j] = indexColorNewTetromino;
				}
			}
			limit = 1;
		}
			
		timer = 0;
	}

	timer++;
	return limit;
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
				// Empty space
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case -1:
				// The new tetromino piece, temporarily represented by -1
				boardShapes[i][j].setFillColor(newTetrominoColor);
				break;
			case 1:
				boardShapes[i][j].setFillColor(sf::Color(255, 166, 0));   // Orange
				break;
			case 2:
				boardShapes[i][j].setFillColor(sf::Color(245, 152, 245)); // Pink
				break;
			case 3:
				boardShapes[i][j].setFillColor(sf::Color(51, 202, 153));  // Green
				break;
			case 4:
				boardShapes[i][j].setFillColor(sf::Color(255, 110, 110)); // Red
				break;
			case 5:
				boardShapes[i][j].setFillColor(sf::Color(255, 202, 77));  // Yellow
				break;
			case 6:
				boardShapes[i][j].setFillColor(sf::Color(166, 166, 255)); // Blue
				break;
			case 7:
				boardShapes[i][j].setFillColor(sf::Color(133, 194, 247)); // Light Blue
				break;
			default:
				boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));    // Default color for any unexpected cases
				break;
			}
		}
	}
}

void Board::UpdateLimitTimer(int limitT) 
{
	limitTimer = limitT;
}


void Board::draw(sf::RenderTarget& rt, sf::RenderStates rs) const 
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			rt.draw(boardShapes[i][j], rs);
		}
	}
}