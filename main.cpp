#include <iostream>
#include "Board.h"
#include "SFML/Graphics.hpp"

int main()
{
    // create the window and the classes
    Board board;
    sf::RenderWindow window(sf::VideoMode(400, 400), "TetrisGameSFML");
    window.setFramerateLimit(60);
    board.GenerateTetromino();

    int rightDelay = 0;  // Delay counter for right movement
    int leftDelay = 0;   // Delay counter for left movement

    const int moveDelay = 7;  // Delay between repeated movements

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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
            if (!board.GenerateTetromino())
                window.close();

        board.UpdateBoardColors();
        window.clear(sf::Color(20, 20, 20));
        window.draw(board);
        window.display();
    }

    return 0;
}
