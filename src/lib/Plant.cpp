#include "Plant.h"
#include "Resource.h"

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
        plantTexture[i]
    }

    elapsedDay = 0;
    level = 0;
    waterPercentage = 0;
    soilPercentage = 0;
    this->species = s;

    bloomingDay = Resource::getBloomingDay(s);
    sprite.setTexture(plantTexture[0]);
    sprite.setPosition(300, 30);
    sprite.setScale(0.08f, 0.08f);
}

Plant::~Plant()
{
}

void Plant::fillWater(WaterBucket &bucket)
{
    if (bucket.consume())
    {
        this->waterPercentage = 100;
    }else {
        std::cout<<"NO water in the Bucket!!!"<<std::endl;
    }
}

void Plant::fillEnergy(FertBucket &bucket)
{
    if (bucket.consume())
    {
        this->soilPercentage = 100;
    }else {
        std::cout<<"NO fertilizer in the Bucket!!"<<std::endl;
    }
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
    if (Resource::getBloomingDay(this->species) <= this->elapsedDay)
        return true;
    else
        return false;
}

void Plant::update()
{
    elapsedDay++;

    if (elapsedDay >= (level + 1) * (bloomingDay / 4) && level < 4)
    { // level이 바뀔만큼 날짜가 지났을 때!
        level++;
    }
}

sf::Sprite Plant::getSprite()
{
    return this->sprite;
}

PlantSpecies Plant::getSpecies()
{
    return this->species;
}

void Plant::draw(sf::RenderTarget &target)
{
    target.draw(sprite);
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
    this->sprite = p->getSprite();
}

void PlantSlot::pullPlant()
{
    this->plant = nullptr;
}

Plant *PlantSlot::getPlant()
{
    return this->plant;
}

void PlantSlot::draw(sf::RenderTarget &target)
{
    this->plant->draw(target);
}
//---------------------------------
