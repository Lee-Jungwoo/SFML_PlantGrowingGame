#include "Game.h"

void Game::init()
{
    window = new RenderWindow(VideoMode(720, 1280), "new");
}

void Game::start()
{

    // Plant plant(PlantSpecies::A);
    // plantSlot[0].pushPlant(&plant);

    
    while (window->isOpen())
    {
        Event event;

        window->clear(Color(220, 255, 191, 255));

        
        // plantSlot[0].draw(*window);

        while (window->pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                
            }

            if (event.type == Event::Closed)
                window->close();
        }

        updateEverything();
        drawEverything(window);
        window->display();
    }
}

void Game::updateEverything()
{
}

void Game::drawEverything(sf::RenderTarget *window)
{

    waterBucket.draw(window);
    fertBucket.draw(window);
}