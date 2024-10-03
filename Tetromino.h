#pragma once

#include <iostream>
#include <vector>

// Header class of the tetromino, to consult a piece, rotate it or derotate it
class Tetromino
{
private:
	std::vector<std::vector<std::vector<bool>>> tetromino;
public:
	Tetromino();
	std::vector<std::vector<bool>> ConsultTetromino(int index);
	void RotateTetromino(int index);
	void DerotateTetromino(int index);

};