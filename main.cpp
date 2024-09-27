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

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
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