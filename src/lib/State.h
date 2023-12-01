#ifndef STATE_H
#define STATE_H
#include <set>
#include "Buckets.h"
#include "Plant.h"
#include "PlantResource.h"
enum class PlantSpecies;


enum class Stage
{
    A,
    B,
    C,
    D
};

class GameState
{
private:
    int day;
    Stage stage;
    std::set<PlantSpecies> remainingPlants;

    WaterBucket waterBucket;
    FertBucket fertBucket;
    // PlantResource container;
    PlantSlot plantSlot[4];
    void nextStage(); //if next stage is unavailable, return false,
    bool isStageDone(); 
public:
    GameState();
    void nextDay();
    
};

#endif
