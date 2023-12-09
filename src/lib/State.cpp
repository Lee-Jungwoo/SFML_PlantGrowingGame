#include "State.h"

GameState::GameState()
{
    day = 1;
    gold = 1000;
    stage = Stage::Desert;
    remainingPlants = std::vector<PlantSpecies>{
        PlantSpecies::Carrot,
        PlantSpecies::Millet,
        PlantSpecies::Oat,
        PlantSpecies::Yacon};
    slotNum = 0;
    remainingPlants_Shop = remainingPlants;
}

void GameState::nextStage()
{
    if (!isStageDone())
    {
        std::cout << "Warning: current stage is unfinished." << std::endl;
        return;
    }

    switch (stage)
    {
    case Stage::Desert:
        stage = Stage::Temperate;
        break;

    case Stage::Temperate:
        stage = Stage::Tropical;
        break;

    case Stage::Tropical:
        stage = Stage::End;
        return;
        break;

    default:
        std::cout << "ERROR: current stage is unrecognizable." << std::endl;
        break;
    }

    this->day = 1;
    this->slotNum = 0;
    remainingPlants = *Resource::getPlantsByStage(stage);
    remainingPlants_Shop = remainingPlants;
    
}

bool GameState::isStageDone()
{
    if (this->remainingPlants.empty())
    {
        return true;
    }
    else
        return false;
}

int GameState::getCurrentDay()
{

    return this->day;
}

Stage GameState::getCurrentStage()
{
    return this->stage;
}

int GameState::getGold()
{
    return this->gold;
}

std::vector<PlantSpecies> *GameState::getRemainingPlantsInShop()
{
    return &(this->remainingPlants_Shop);
}

int GameState::getWater()
{
    return this->waterBucket.getRemaining();
}

int GameState::getFert()
{
    return this->fertBucket.getRemaining();
}

void GameState::nextDay()
{

    Plant *plant;
    // 모든 식물들 한번씩 안건드리면 못넘어가게 컨트롤하는 부분
    for (int i = 0; i < 4; i++)
    {
        plant = plantSlot[i].getPlant();
        if (plant == nullptr)
        {
            break;
        }
        else if (!plant->isHandled())
            return;
    }

    this->day++;

    // 슬롯 식물들 하나씩 update 해줌
    for (int i = 0; i < 4; i++)
    {
        plant = plantSlot[i].getPlant();
        if (plant == nullptr)
        {
            continue;
        }
        plant->update();
    }

    // 슬롯의 식물들이 죽었는지 개화했는지, 그대로 갈지 판단함
    for (int i = 0; i < 4; i++)
    {
        plant = plantSlot[i].getPlant();
        if (plant == nullptr)
            continue;

        if (plant->isDead())
        {
            std::cout << "Plant dead => " << Resource::getName(plant->getSpecies()) << std::endl;
            plantSlot[i].pullPlant();
            remainingPlants_Shop.push_back(plant->getSpecies());
            slotNum--;
        }
        else if (plant->isBlooming())
        {
            std::cout << "Blooming!!! =>" << Resource::getName(plant->getSpecies()) << std::endl;

            /**
             * Remove the plant in the remaining plants list.
             **/
            for (std::vector<PlantSpecies>::iterator iter = remainingPlants.begin(); iter != remainingPlants.end(); iter++)
            {
                if (plant->getSpecies() == (*iter))
                {
                    remainingPlants.erase(iter);
                    break;
                }
            }

            plantSlot[i].pullPlant();
            plantBook.push_back(plant->getSpecies());

            slotNum--;
            this->gold = this->gold + 1000;
        }
    }

    // 다음 스테이지로 넘어갈지 말지.
    if (this->isStageDone())
    {
        this->nextStage();
        this->day = 1;
    }
    addGold(50);

    std::cout << "GAMESTATE: succesfully going to next day." << std::endl;
}

PlantSlot *GameState::getPlantSlot(int i) // 인덱스 0~3
{
    return &(this->plantSlot[i]);
}

std::vector<PlantSpecies> *GameState::getPlantBook()
{
    return &plantBook;
}

void GameState::setStageInDict(Stage stage)
{
    this->stage_dict = stage;
}

sf::Sprite *GameState::getWaterBucketSprite()
{
    return this->waterBucket.getSprite();
}

sf::Sprite *GameState::getFertBucketSprite()
{
    return this->fertBucket.getSprite();
}

void GameState::buyNewPlant(int num) 
{
    std::vector<PlantSpecies>::iterator i = remainingPlants_Shop.begin();

    i = i + (num - 1);
    PlantSpecies s = *i;
    if (Resource::getPrice(s) > gold)
    {
        std::cout << "ERROR: not enough money" << std::endl;
        return;
    }
    else
        gold -= Resource::getPrice(s);

    remainingPlants_Shop.erase(i);

    plantSlot[slotNum] = PlantSlot();
    plantSlot[slotNum++].pushPlant(new Plant(s)); 
}

bool GameState::isAllHandled()
{
    for (int i = 0; i < 4; i++)
    {
        if (plantSlot[i].getPlant() == nullptr)
            return true; // Return when nullptr. (end of the plants)
        if (!plantSlot[i].getPlant()->isHandled())
            return false;
    }
    return true;
}

int GameState::getSlotNum()
{
    return slotNum;
}

WaterBucket *GameState::getWaterBucket()
{
    return &waterBucket;
}

FertBucket *GameState::getFertBucket()
{
    return &fertBucket;
}

void GameState::addGold(int a)
{
    gold += a;
}

/*
DEBUGGING---------------------------------------------------------
*/

void GameState::make_next_available()
{
    this->remainingPlants = std::vector<PlantSpecies>();
}
