#include <iostream>
#include "Board.h"
#include "UserInterface.h"
#include "SFML/Graphics.hpp"
#include <fstream>

int main()
{
    // create the window and the classes
    Board board;
    UserInterface userInterface;

    sf::RenderWindow window(sf::VideoMode(400, 400), "TetrisGameSFML");
    window.setFramerateLimit(60);

    int rightDelay = 0;  // Delay counter for right movement
    int leftDelay = 0;   // Delay counter for left movement
    int up = 0;

    int score = 0;
    int maxScore = 0;

    std::ifstream in("resources/maxScore.txt");
    in >> maxScore;

    userInterface.SetMaxScore(maxScore);
    userInterface.SetScore(score);

    bool live = 0;

    const int moveDelay = 7;  // Delay between repeated movements

    // Generate the first tetromino and set the game live
    board.GenerateTetromino();
    live = 1; // Fix: Set the game to live after generating the first tetromino

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (live)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !up)
            {
                board.RotateTetromino();
                up = 1;
            }
            else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                up = 0;

            // Check if down key is pressed (fast drop)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                board.UpdateLimitTimer(5);
            else
                board.UpdateLimitTimer(30);

            // Handle right key movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (rightDelay == 0)  // Move piece right if delay is 0
                {
                    board.Right();
                    rightDelay = moveDelay;  // Reset the delay
                }
            }

            if (rightDelay > 0)
                rightDelay--;  // Decrease the right delay counter

            // Handle left key movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (leftDelay == 0)  // Move piece left if delay is 0
                {
                    board.Left();
                    leftDelay = moveDelay;  // Reset the delay
                }
            }

            if (leftDelay > 0)
                leftDelay--;  // Decrease the left delay counter

            // Update the board and generate new pieces if needed
            if (board.UpdateBoard())
            {
                if (!board.GenerateTetromino())
                {
                    live = 0; // End the game if a new piece can't be generated
                    if (score > maxScore)
                    {
                        userInterface.NewScore();
                        std::ofstream out("maxScore.txt");
                        out << score;
                    }
                    else
                        userInterface.GameOver();
                }
            }

            board.UpdateBoardColors();

            int newScore = board.CheckLine() * 5;
            score += newScore;
            userInterface.SetScore(score);
        }

        window.clear(sf::Color(20, 20, 20));
        window.draw(board);
        window.draw(userInterface);
        window.display();
    }

    return 0;
}
