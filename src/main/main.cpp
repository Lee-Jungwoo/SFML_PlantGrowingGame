#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../lib/BackGround.h"
#include "../lib/State.h"
#include "../lib/Resource.h"

using namespace sf;

int main()
{
    //GameState gamestate;
    RenderWindow* window = new RenderWindow(VideoMode(540,900), "new");
    

    Vector2f size = window->getView().getSize();

    BackGround B;


    while (window->isOpen())
    {
        Event event;
        window->clear(Color(220, 255, 191, 255));

        B.draw(window);


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
                    sf::Vector2i pos = sf::Mouse::getPosition(*window);
                    B.ChangeMode(pos);
                    break;
                }
                default:
                    break;
                }
            }
       
          
        }










        window->display();
    }

    return 0;
}

