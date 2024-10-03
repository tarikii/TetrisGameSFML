#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Board.h"
#include "Tetromino.h"

class UserInterface : public sf::Drawable
{
private:
    sf::RectangleShape topRectangle;
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

    // Adjust the position of the active tetromino display
    sf::Vector2f activePiecePosition = sf::Vector2f(265, 50); // Coordinates for the piece display

public:
    UserInterface();

    void SetScore(int score);
    void SetMaxScore(int maxScore);
    void GameOver();
    void MaxScore();
    void DrawActivePiece(const Board& board, sf::RenderTarget& rt); // New function to draw the active piece

    virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override;
};