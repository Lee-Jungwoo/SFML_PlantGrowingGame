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
    std::vector<PlantSpecies> remainingPlants; // 현재 스테이지 개화 안한 식물 목록
                                               // 포인터 아닌 이유는, resource의 파일내용을 바꾸면 안돼서..?!

    std::vector<PlantSpecies> remainingPlants_Shop; // 현재 상점에 남은 식물 목록
    
    std::vector<PlantSpecies> plantBook; //개화시킨 식물들의 도감
    


    WaterBucket waterBucket;
    FertBucket fertBucket;
    PlantSlot plantSlot[4];
    int slotNum;
    


    void nextStage();
    bool isStageDone();

public:
    GameState();
    int getCurrentDay();
    Stage getCurrentStage();
    int getGold();
    
    int getWater();
    int getFert();

    std::vector<PlantSpecies> *getRemainingPlantsInShop(); // 상점에서 쓸거

    sf::Sprite *getWaterBucketSprite();
    sf::Sprite *getFertBucketSprite();

    void nextDay();
    PlantSlot *getPlantSlot(int i); //0 ~ 3 인덱스 줄수 있음

    bool isAllHandled();

    void buyNewPlant(int num);

    int getSlotNum(); //actual index. (0~3)
    WaterBucket* getWaterBucket();
    FertBucket *getFertBucket();

    /*****************************
     * DEBUGGING
    *****************************/
    void make_next_available();
    std::vector<PlantSpecies> getA(){ 
        std::cout<<"not yet bloom:"<<std::endl;
        
        return remainingPlants;};
    std::vector<PlantSpecies> getB(){
        std::cout<<"On the Shop:"<<std::endl;
        return remainingPlants_Shop;};
    std::vector<PlantSpecies> getC(){ 
        std::cout<<"On the book:"<<std::endl;
        return plantBook;};

    void fillMoney(){
        this->gold = 99999999;
    }

};

#endif
