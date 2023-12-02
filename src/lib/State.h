#ifndef STATE_H
#define STATE_H
#include <set>
#include "Buckets.h"
#include "Plant.h"
#include "Resource.h"

class GameState
{
private:
    int day;
    Stage stage;
    std::set<PlantSpecies> remainingPlants; //현재 스테이지 남은 식물 목록

    WaterBucket waterBucket;
    FertBucket fertBucket;
    // PlantResource container;
    PlantSlot plantSlot[4];  // plantSlot.getPlant() 
    void nextStage(); 
    bool isStageDone(); 

public:
    GameState();
    void nextDay();
    PlantSlot * getPlantSlot(int i);


    
};












#endif
