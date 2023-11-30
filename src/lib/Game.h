#ifndef GAME_H
#define GAME_H

#include "Buckets.h"
#include "Plant.h"



class Game{
private:
    WaterBucket waterBucket;
    FertBucket fertBucket;

    PlantSlot plantSlot[4];

public:
    void drawEverything(sf::RenderTarget * window){
        
        waterBucket.draw(window);
        fertBucket.draw(window);
    }
};

#endif