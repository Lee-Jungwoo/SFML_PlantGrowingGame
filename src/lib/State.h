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
    int gold;
    std::vector<PlantSpecies> remainingPlants; //현재 스테이지 남은 식물 목록
                                               //포인터 아닌 이유는, resource의 파일내용을 바꾸면 안돼서..?!

    WaterBucket waterBucket;
    FertBucket fertBucket;
    PlantSlot plantSlot[4];
    

    void nextStage();
    bool isStageDone();

public:

    GameState();
    int getCurrentDay();
    Stage getCurrentStage();
    int getGold();
    std::set<PlantSpecies> * getRemainingPlants(); //상점에서 쓸거
    void nextDay();
    PlantSlot * getPlantSlot(int i);

};












#endif
