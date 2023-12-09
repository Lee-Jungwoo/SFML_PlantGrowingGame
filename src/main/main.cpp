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
    window->setFramerateLimit(20);

    Vector2f size = window->getView().getSize();

    
    GameState state;
    // state.fillMoney();
    BackGround B(state, window);
    
    B.draw(state);
    Event event;
    while (window->isOpen())
    {
        //clear previous frame
        window->clear(Color(220, 255, 191, 255));
        
        //do the inner work
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
            if (event.type == Event::MouseButtonPressed)
            {
                switch (event.mouseButton.button)
                {
                case Mouse::Left:
                {
                    //Get Mouse Position
                    sf::Vector2i pos = sf::Mouse::getPosition(*window); 
                    std::cout<<pos.x<< " "<<pos.y<<std::endl;
                    //call background's function with position and state
                    B.ChangeMode(pos, state);
                    break;
                }
                default:
                    break;
                }
            }
        }
        
        //draw to window
        B.draw(state);
        //display to screen
        window->display();
    }

    return 0;
}

