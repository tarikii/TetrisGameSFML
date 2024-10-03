#include "Tetromino.h"

// Create each tetromino piece with the help of matrix values
Tetromino::Tetromino()
{
	tetromino = { {{1,1},
			 {1,1}},

			{{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,0,1,0},
			 {0,0,0,0,0}},

			{{0,0,0,0,0},
			 {0,0,0,1,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},

			{{0,0,0,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},

			{{0,0,0,0,0},
			 {0,1,1,0,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},

			{{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},

			{{0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0}} };
}


// Consult the tetromino pìece with the help of the index
std::vector<std::vector<bool>> Tetromino::ConsultTetromino(int index)
{
	return tetromino[index];
}


void Tetromino::RotateTetromino(int index)
{

	// Store the current state of the tetromino in a temporary vector
	std::vector<std::vector<bool>> auxiliarTetromino = tetromino[index];

	int indexI = 0, indexJ = 0;
	int tetrominoSize = (int)tetromino[index].size();

	// Perform a 90-degree rotation (clockwise)
	for (int i = 0; i < tetrominoSize; i++)
	{
		for (int j = tetrominoSize - 1; j >= 0; j--)
		{
			// Set the new position in the tetromino with the rotated values
			tetromino[index][indexI][indexJ] = auxiliarTetromino[j][i];

			indexJ++; // Move to the next column in the new position
		}
		indexI++; // Move to the next row in the new position
		indexJ = 0;
	}
}

// Same thing as rotate, but in reverse
void Tetromino::DerotateTetromino(int index)
{
	std::vector<std::vector<bool>> auxiliarTetromino = tetromino[index];
	int indexI = 0, indexJ = 0;
	int tetrominoSize = (int)tetromino[index].size();
	for (int i = tetrominoSize - 1; i >= 0; i--)
	{
		for (int j = 0; j < tetrominoSize; j++)
		{
			tetromino[index][indexI][indexJ] = auxiliarTetromino[j][i];
			indexJ++;
		}
		indexI++;
		indexJ = 0;
	}
}