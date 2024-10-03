#include "UserInterface.h"

UserInterface::UserInterface()
{
	// Load the font from a file; if it fails, print an error message
	if (!font.loadFromFile("resources/SamuraiBlast.ttf"))
		std::cout << "Error laoding the font text" << std::endl;

	// Load the elements of the interface (score title, score, max score title, max score, by text) and set the font,colors,position...
	textScoreTitle.setFont(font);
	textScoreTitle.setFillColor(sf::Color::White);
	textScoreTitle.setPosition(sf::Vector2f(265, 25));
	textScoreTitle.setString("Score");
	textScoreTitle.setCharacterSize(20);

	textMaxScoreTitle.setFont(font);
	textMaxScoreTitle.setFillColor(sf::Color::White);
	textMaxScoreTitle.setPosition(sf::Vector2f(240, 200));
	textMaxScoreTitle.setString("Max Score");
	textMaxScoreTitle.setCharacterSize(20);

	textScore.setFont(font);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(sf::Vector2f(260, 70));

	textMaxScore.setFont(font);
	textMaxScore.setFillColor(sf::Color::White);
	textMaxScore.setPosition(sf::Vector2f(260, 250));

	textBy.setFont(font);
	textBy.setFillColor(sf::Color::White);
	textBy.setPosition(sf::Vector2f(250, 370));
	textBy.setString("By Tarik");
	textBy.setCharacterSize(20);

	textGameOver.setFont(font);
	textGameOver.setFillColor(sf::Color::Red);
	textGameOver.setPosition(sf::Vector2f(100, 150));
	textGameOver.setString("Game Over");
	textGameOver.setCharacterSize(25);

	textNewScore.setFont(font);
	textNewScore.setFillColor(sf::Color::Green);
	textNewScore.setPosition(sf::Vector2f(100, 150));
	textNewScore.setString("New Record");
	textNewScore.setCharacterSize(25);
}

// Format and set the score string based on its value
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

// Format and set the max score string based on its value
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

// Set the game over flag to true
void UserInterface::GameOver()
{
	gameOver = 1;
}

// Set the new record flag to true
void UserInterface::MaxScore()
{
	newRecord = 1;
}


// Draw all the elements that were composed before for the interface
void UserInterface::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	rt.draw(textScoreTitle, rs);
	rt.draw(textScore, rs);
	rt.draw(textMaxScoreTitle, rs);
	rt.draw(textMaxScore, rs);
	rt.draw(textBy, rs);

	// Draw game over or new record messages if the flags are set
	if (gameOver)
		rt.draw(textGameOver, rs);

	if (newRecord)
		rt.draw(textNewScore, rs);
}