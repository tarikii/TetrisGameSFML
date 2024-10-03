#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("resources/SamuraiBlast.ttf"))
		std::cout << "Error loading the font text" << std::endl;

	// Initialize the rectangle
	topRectangle.setSize(sf::Vector2f(90, 90)); // Set size (width, height) as needed
	topRectangle.setFillColor(sf::Color::Transparent); // No fill color
	topRectangle.setOutlineColor(sf::Color::White); // Outline color
	topRectangle.setOutlineThickness(2); // Set the thickness of the outline
	topRectangle.setPosition(255, 25); // Position at the desired location

	// Set an offset for moving down text elements
	const float offset = 90; // height of the rectangle

	textScoreTitle.setFont(font);
	textScoreTitle.setFillColor(sf::Color::White);
	textScoreTitle.setPosition(sf::Vector2f(265, 155)); // Move down
	textScoreTitle.setString("Score");
	textScoreTitle.setCharacterSize(20);

	textMaxScoreTitle.setFont(font);
	textMaxScoreTitle.setFillColor(sf::Color::White);
	textMaxScoreTitle.setPosition(sf::Vector2f(240, 280)); // Move down
	textMaxScoreTitle.setString("Max Score");
	textMaxScoreTitle.setCharacterSize(20);

	textScore.setFont(font);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(sf::Vector2f(260, 175)); // Move down

	textMaxScore.setFont(font);
	textMaxScore.setFillColor(sf::Color::White);
	textMaxScore.setPosition(sf::Vector2f(260, 305)); // Move down

	textBy.setFont(font);
	textBy.setFillColor(sf::Color::White);
	textBy.setPosition(sf::Vector2f(250, 370)); // Keep the same position
	textBy.setString("By Tarik");
	textBy.setCharacterSize(20);

	textGameOver.setFont(font);
	textGameOver.setFillColor(sf::Color::Red);
	textGameOver.setPosition(sf::Vector2f(100, 150 + offset)); // Move down
	textGameOver.setString("Game Over");
	textGameOver.setCharacterSize(25);

	textNewScore.setFont(font);
	textNewScore.setFillColor(sf::Color::Green);
	textNewScore.setPosition(sf::Vector2f(100, 150 + offset)); // Move down
	textNewScore.setString("New Record");
	textNewScore.setCharacterSize(25);
}


void UserInterface::SetScore(int score)
{
	if (score <= 9)
		textScore.setString("000" + std::to_string(score));  // 000X
	else if (score <= 99)
		textScore.setString("00" + std::to_string(score));   // 00XX
	else if (score <= 999)
		textScore.setString("0" + std::to_string(score));    // 0XXX
	else if (score <= 9999)
		textScore.setString(std::to_string(score));          // XXXX
	else
		textScore.setString("9999");  // Limit score display to 9999
}

void UserInterface::SetMaxScore(int maxScore)
{
	if (maxScore <= 9)
		textMaxScore.setString("000" + std::to_string(maxScore));  // 000X
	else if (maxScore <= 99)
		textMaxScore.setString("00" + std::to_string(maxScore));   // 00XX
	else if (maxScore <= 999)
		textMaxScore.setString("0" + std::to_string(maxScore));    // 0XXX
	else if (maxScore <= 9999)
		textMaxScore.setString(std::to_string(maxScore));          // XXXX
	else
		textMaxScore.setString("9999");  // Limit max score display to 9999
}


void UserInterface::GameOver()
{
	gameOver = 1;
}

void UserInterface::MaxScore()
{
	newScore = 1;
}


void UserInterface::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	rt.draw(topRectangle, rs);
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