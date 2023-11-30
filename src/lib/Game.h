#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Buckets.h"
#include "Plant.h"
#include "PlantResource.h"

using namespace sf;

class Game{
private:
    WaterBucket waterBucket;
    FertBucket fertBucket;
    PlantResource container;
    PlantSlot plantSlot[4];

    RenderWindow * window;

public:


    void init();
    void start();

    void updateEverything();

    void drawEverything(sf::RenderTarget * window);
};

#endif