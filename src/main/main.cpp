#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../lib/State.h"
#include "../lib/Resource.h"

using namespace sf;
int main()
{

    RenderWindow *window = new RenderWindow(VideoMode(540, 900), "game");
Plant p = Plant(PlantSpecies::Carrot);
    while (window->isOpen())
    {
        
        // sf::Texture t = *Resource::getTexture(PlantSpecies::Carrot, 4);

        // sf::Sprite s(t);

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
                    p.update();
                }
                break;
                default:
                    break;
                }
            }
        }
        // window->draw(s);
        p.draw(*window);
        window->display();
    }

    return 0;
}