#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Board.h"

// Header class of the user interface, where it shows the information of the score and the max score
class UserInterface : public sf::Drawable
{
private:
	sf::Font font;
	sf::Text textScoreTitle;
	sf::Text textScore;
	sf::Text textMaxScoreTitle;
	sf::Text textMaxScore;
	sf::Text textBy;
	sf::Text textGameOver;
	sf::Text textNewScore;
	bool newRecord = 0;
	bool gameOver = 0;

public:
	UserInterface();
	void SetScore(int score);
	void SetMaxScore(int maxScore);
	void GameOver();
	void MaxScore();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};