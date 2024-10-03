#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Board.h"

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
	bool newScore = 0;
	bool gameOver = 0;

public:
	UserInterface();
	void SetScore(int score);
	void SetMaxScore(int maxScore);
	void GameOver();
	void MaxScore();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};