#include "State.h"


GameState::GameState()
{
    day = 0;
    stage = Stage::A;
    remainingPlants = std::set<PlantSpecies>{PlantSpecies::A, PlantSpecies::B, PlantSpecies::C};
}

void GameState::nextStage()
{
    switch (stage)
    {
    case Stage::A:
        stage = Stage::B;

        break;
    case Stage::B:
        stage = Stage::C;

        break;
    case Stage::C:
        stage = Stage::D;

        break;
    case Stage::D:
        std::cout << "ERROR: current stage is the last stage." << std::endl;

        break;

    default:
        std::cout << "ERROR: current stage is unrecognizable." << std::endl;
        break;
    }
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

void GameState::nextDay()
{
    this->day++;
    Plant *plant;

    // 슬롯의 식물들이 죽었는지 개화했는지, 그대로 갈지 판단함
    for (int i = 0; i < 4; i++)
    {
        plant = plantSlot[i].getPlant();
        if (plant->isDead())
        {
            std::cout << "Plant dead => " << PlantResource::getName(plant->getSpecies()) << std::endl;
            plantSlot[i].pullPlant();
        }
        else if (plant->isBlooming())
        {
            std::cout << "Blooming!!! =>" << PlantResource::getName(plant->getSpecies()) << std::endl;

            /**
             * Remove the plant in the remaining plants list.
             **/
            for (std::set<PlantSpecies>::iterator iter = remainingPlants.begin(); iter != remainingPlants.end(); iter++)
            {
                if (plant->getSpecies() == (*iter))
                {
                    remainingPlants.erase(iter);
                    break;
                }
            }
            plantSlot[i].pullPlant();
        }
    }



    // 다음 스테이지로 넘어갈지 말지.

    if(this->isStageDone()){
        this->nextStage(); //이때 백그라운드랑 스텟바 바꿔주면 되겠구만용

    }
}