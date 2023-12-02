#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../lib/Game.h"

using namespace sf;
int main()
{
    Game game;

    RenderWindow *window = new RenderWindow(VideoMode(540, 900), "game");

    while (window->isOpen())
    {
        Event event;
        window->clear(Color(220, 255, 191, 255));

        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
            if (event.type == Event::MouseButtonPressed)
            {
                switch (event.key.code)
                {
                case Mouse::Left:
                {
                    // sf::Vector2i pos = sf::Mouse::getPosition(*window);
                    // B.ChangeMode(pos);
                    // break;
                    std::cout<<"hello world"<<std::endl;
                }
                }
            }
        }

        window->display();
    }

    return 0;
}