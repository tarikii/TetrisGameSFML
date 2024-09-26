#include <iostream>
#include <vector>

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