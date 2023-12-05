#include "Plant.h"
#include "Resource.h"
#include <cassert>

/**
 *
 *
 * Plant
 *
 *
 * */
Plant::Plant(PlantSpecies s)
{
    handled = false;
    
    /**
     * Load every image file to single plant 객체
     * from 1단계 to Dead.
     */
    for(int i=0;i<=PLANT_LEVEL;i++){
        plantTexture[i] = Resource::getTexture(s, i);
        std::cout<<"Texture loaded?"<<std::endl;
    }

    elapsedDay = 0;
    level = 1;
    waterPercentage = 100;
    soilPercentage = 100;

    this->species = s;

    price = Resource::getPrice(species);
    bloomingDay = Resource::getBloomingDay(s);

    sprite = new sf::Sprite();
    sprite->setTexture(*plantTexture[1]);
    sprite->setPosition(300, 30);
    sprite->setScale(0.8f, 0.8f);
}

Plant::~Plant()
{
    delete sprite;
    
}

void Plant::fillWater(WaterBucket &bucket)
{
    if(handled) return;
    if (bucket.consume())
    {
        this->waterPercentage = 100;
    }
    else
    {
        std::cout << "NO water in the Bucket!!!" << std::endl;
    }

    handled = true;
}

void Plant::fillEnergy(FertBucket &bucket)
{
    if(handled) return;
    if (bucket.consume())
    {
        this->soilPercentage = 100;
    }
    else
    {
        std::cout << "NO fertilizer in the Bucket!!" << std::endl;
    }
    handled = true;
}

void Plant::skipThisTime()
{
    handled = true;
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
    handled = false;

    elapsedDay++;

    // level이 바뀔만큼 날짜가 지났을 때!
    if (elapsedDay >= (level + 1) * (bloomingDay / 4) && level < 4)
    {   
            
        level++;
        sprite->setTexture(*plantTexture[level], true);
    }

    this->soilPercentage -= 10;
    this->waterPercentage -= 10;
    assert(level <= 4 && level >= 1);

    std::cout<<"Plant:" +Resource::getName(species)+" successfully going to next day."<<std::endl;
}

sf::Sprite * Plant::getSprite()
{
    return this->sprite;
}

PlantSpecies Plant::getSpecies()
{
    return this->species;
}

int Plant::getPrice()
{
    return price;
}


void Plant::draw(sf::RenderTarget &target)
{
    target.draw(*sprite);
}

int Plant::getPercentage() {return (level - 1)*25;}
int Plant::getwaterPercentage() {return waterPercentage;}
int Plant::getSoilpercentage() {return soilPercentage;}


/**
 * DEBUGGING--------------------------------------------
*/
void Plant::kill()
{
    this->waterPercentage = 0;
    this->handled = true;
}

void Plant::bloom()
{
    this->elapsedDay = bloomingDay;
    this->handled = true;
}
//-------------------------------

/**
 *   PlantSlot
 *
 */
PlantSlot::PlantSlot() : plant(nullptr)
{
    this->slotTexture = sf::Texture();
    this->slotTexture.loadFromFile("../../assets/PlantSlot.png");
    this->sprite = new sf::Sprite(this->slotTexture);
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

sf::Sprite * PlantSlot::getSprite()
{
    return this->sprite;
}

void PlantSlot::draw(sf::RenderTarget &target)
{

    this->plant->draw(target);
}

//---------------------------------
