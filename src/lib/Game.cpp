#include "Game.h"

void Game::init()
{
    window = new RenderWindow(VideoMode(720, 1280), "new");
}

void Game::render()
{
    while (window->isOpen())
    {
        Event event;

        window->clear(Color(220, 255, 191, 255));

        waterBucket.draw(window);

        while (window->pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                
            }

            if (event.type == Event::Closed)
                window->close();
        }
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