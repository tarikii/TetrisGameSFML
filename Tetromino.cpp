#include "Tetromino.h"

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


std::vector<std::vector<bool>> Tetromino::ConsultTetromino(int index)
{
	return tetromino[index];
}


void Tetromino::RotateTetromino(int index)
{
	std::vector<std::vector<bool>> auxiliarTetromino = tetromino[index];
	int indexI = 0, indexJ = 0;
	int tetrominoSize = (int)tetromino[index].size();
	for (int i = 0; i < tetrominoSize; i++)
	{
		for (int j = tetrominoSize - 1; j >= 0; j--)
		{
			tetromino[index][indexI][indexJ] = auxiliarTetromino[j][i];
			indexJ++;
		}
		indexI++;
		indexJ = 0;
	}
}

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