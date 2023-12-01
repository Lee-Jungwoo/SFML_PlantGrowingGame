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

        this->nextDay();
        this->drawEverything(window);

        window->display();
    }
}

void Game::nextDay() //모든 slot의 식물에 물을 주었다는 가정.
{
    this->gameState.nextDay();
    for(int i=0;i<4;i++){
        // gameState.plantSlot[i].getPlant()->update();
    }
}

void Game::drawEverything(sf::RenderTarget *window)
{

    // waterBucket.draw(window);
    // fertBucket.draw(window);

}

