#include "State.h"

GameState::GameState()
{
    day = 1;
    gold = 0;
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
        std::cout << "ERROR: current stage is the last stage." << std::endl;
        break;

    default:
        std::cout << "ERROR: current stage is unrecognizable." << std::endl;
        break;
    }

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

int GameState::getWater(){
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
        if (plant == nullptr || plant->isHandled())
        {
            return;
        }
    }

    this->day++;
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
}

PlantSlot *GameState::getPlantSlot(int i) //인덱스 0~3
{
    return (this->plantSlot) + i;
}

sf::Sprite *GameState::getWaterBucketSprite()
{
    return this->waterBucket.getSprite();
}

sf::Sprite *GameState::getFertBucketSprite()
{
    return this->fertBucket.getSprite();
}

void GameState::buyNewPlant(int num) // 1~ 4 집어넣어주면 됨.
{
    std::vector<PlantSpecies>::iterator i = remainingPlants_Shop.begin();

    i = i + (num - 1);
    remainingPlants_Shop.erase(i);

    PlantSpecies s = *i;

    if (Resource::getPrice(s) > gold)
    {
        std::cout << "ERROR: not enough money" << std::endl;
    }

    plantSlot[slotNum] = PlantSlot();
    plantSlot->pushPlant(new Plant(s));
}

bool GameState::isAllHandled()
{
    for(int i=0;i<4;i++){
        if(plantSlot[i].getPlant() == nullptr) return true; //Return when nullptr. (end of the plants)
        if(!plantSlot[i].getPlant()->isHandled())
            return false;
    }
    return true;
}
