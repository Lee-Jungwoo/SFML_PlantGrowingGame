#include "Plant.h"
#include "PlantResourceContainer.h"

/**
 *
 *
 * Plant
 *
 *
 * */

Plant::Plant(PlantSpecies s)
{
    for (int i = 0; i < PLANT_LEVEL; i++)
    {
        // plantTexture[i].loadFromFile
        // PlantContainer에서 사진 끌어오기
    }

    elapsedDay = 0;
    level = 0;
    waterPercentage = 0;
    soilPercentage = 0;
    this->species = s;
    bloomingDay = PlantResourceContainer::getBloomingDay(s);
    sprite.setTexture(plantTexture[0]);
}

void Plant::fillWater()
{
    this->waterPercentage = 100;
}

void Plant::fillEnergy()
{
    this->soilPercentage = 100;
}

bool Plant::isDead()
{
    if (this->waterPercentage <= 25 || this->soilPercentage <= 25)
        return true;
    else
        return false;
}

bool Plant::isBlooming()
{
    if(PlantResourceContainer::getBloomingDay(this->species) <= this->elapsedDay)
        return true;
    else 
        return false;
}



//-------------------------------

/**
 *   PlantSlot
 *
 */
PlantSlot::PlantSlot() : plant(nullptr)
{
}

bool PlantSlot::isEmpty()
{
    if (plant == nullptr)
    {
        return true;
    }
    return false;
}

void PlantSlot::pushPlant(Plant *p)
{
    this->plant = p;
}

void PlantSlot::pullPlant()
{
    this->plant = nullptr;
}
//-------------------