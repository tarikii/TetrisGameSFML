#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("resources/arial.ttf"))
		std::cout << "Error laoding the font text" << std::endl;

	textScoreTitle.setFont(font);
	textScoreTitle.setFillColor(sf::Color::White);
	textScoreTitle.setPosition(sf::Vector2f(255, 25));
	textScoreTitle.setString("Score");

	textMaxScoreTitle.setFont(font);
	textMaxScoreTitle.setFillColor(sf::Color::White);
	textMaxScoreTitle.setPosition(sf::Vector2f(225, 200));
	textMaxScoreTitle.setString("Max Score");
	textMaxScoreTitle.setCharacterSize(20);

	textScore.setFont(font);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(sf::Vector2f(250, 70));

	textMaxScore.setFont(font);
	textMaxScore.setFillColor(sf::Color::White);
	textMaxScore.setPosition(sf::Vector2f(265, 245));

	textBy.setFont(font);
	textBy.setFillColor(sf::Color::White);
	textBy.setPosition(sf::Vector2f(260, 370));
	textBy.setString("By Tarik");
	textBy.setCharacterSize(20);

	textGameOver.setFont(font);
	textGameOver.setFillColor(sf::Color::White);
	textGameOver.setPosition(sf::Vector2f(8, 150));
	textGameOver.setString("Game Over");
	textGameOver.setCharacterSize(25);

	textNewScore.setFont(font);
	textNewScore.setFillColor(sf::Color::White);
	textNewScore.setPosition(sf::Vector2f(8, 150));
	textNewScore.setString("New Record");
	textNewScore.setCharacterSize(25);
}

void UserInterface::SetScore(int score)
{
	if (score <= 9)
		textScore.setString("000" + std::to_string(score));
	else if (score <= 99)
		textScore.setString("00" + std::to_string(score));
	else if (score <= 999)
		textScore.setString("000" + std::to_string(score));
	else if (score <= 9999)
		textScore.setString(std::to_string(score));
	else
		textScore.setString("9999");
}

void UserInterface::SetMaxScore(int maxScore)
{
	if (maxScore <= 9)
		textMaxScore.setString("000" + std::to_string(maxScore));
	else if (maxScore <= 99)
		textMaxScore.setString("00" + std::to_string(maxScore));
	else if (maxScore <= 999)
		textMaxScore.setString("000" + std::to_string(maxScore));
	else if (maxScore <= 9999)
		textMaxScore.setString(std::to_string(maxScore));
	else
		textMaxScore.setString("9999");
}

void UserInterface::GameOver()
{
	gameOver = 1;
}

void UserInterface::NewScore()
{
	newScore = 1;
}

void UserInterface::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	rt.draw(textScoreTitle, rs);
	rt.draw(textScore, rs);
	rt.draw(textMaxScoreTitle, rs);
	rt.draw(textMaxScore, rs);
	rt.draw(textBy, rs);

	if (gameOver)
		rt.draw(textGameOver, rs);

	if (newScore)
		rt.draw(textNewScore, rs);
}