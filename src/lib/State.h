#ifndef STATE_H
#define STATE_H
#include <vector>
#include "Buckets.h"
#include "Plant.h"

enum class PlantSpecies;
class PlantResource;

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
    std::vector<PlantSpecies> * remainingPlants;

    WaterBucket waterBucket;
    FertBucket fertBucket;
    // PlantResource container;
    PlantSlot plantSlot[4];

public:
    void nextDay();
    
};

#endif
