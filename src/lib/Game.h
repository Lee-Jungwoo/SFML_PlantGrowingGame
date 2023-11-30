#ifndef GAME_H
#define GAME_H

#include "Buckets.h"
#include "Plant.h"
#include "PlantResourceContainer.h"



class Game{
private:
    WaterBucket waterBucket;
    FertBucket fertBucket;
    PlantResourceContainer container;
    PlantSlot plantSlot[4];

public:

    void updateEverything();

    void drawEverything(sf::RenderTarget * window);
};

#endif