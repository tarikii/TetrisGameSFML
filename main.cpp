#include <iostream>
#include "SFML/Graphics.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "TetrisGameSFML");
    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(20, 20, 20));
        window.display();
    }

    return 0;
}