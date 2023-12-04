#include "Buckets.h"
#include <iostream>


/** 
 *  BUCKET              
 **/
Bucket::Bucket()
{   
    remaining = 100;
    texture = new sf::Texture();
    sprite = new sf::Sprite();
}

Bucket::~Bucket()
{
    delete texture;
    delete sprite;
}

bool Bucket::consume()
{
    if (this->isEmpty())
    {
        return false;
    }
    else
    {
        remaining -= 25;
        return true;
    }
}

void Bucket::fill()
{
    remaining = BUCKET_CAPACITY;

    std::cout << remaining << std::endl;
}

void Bucket::draw(sf::RenderTarget *window)
{
    window->draw(sf::Sprite(*texture));
}

sf::Sprite *Bucket::getSprite()
{  
    return this->sprite;
}

int Bucket::getRemaining()
{
    return remaining;
}

bool Bucket::isEmpty()
{
    return (remaining == 0);
}


sf::Texture *Bucket::getTexture()
{
    return texture;
}

/*----------------------------*/

/**
 *    WATERBUCKET              
 * */
WaterBucket::WaterBucket()
{
    texture->loadFromFile("../../assets/Buckets/WaterBucket.png");

    sprite->setPosition(sf::Vector2f(200.f, 30.f));
    sprite->setTexture(*texture, true);
    sprite->setScale(0.5f,0.5f);
}

void WaterBucket::draw(sf::RenderTarget *window)
{
    window->draw(*sprite);
}




/*----------------------------*/


/**
 *     FERTBUCKET              
 */
FertBucket::FertBucket()
{

    /*
    * 이거 나중에  for문으로 돌리기
    */
    texture->loadFromFile("../../assets/Buckets/FertBucket.png");

    sprite->setPosition(sf::Vector2f(300.f, 30.f));
    sprite->setTexture(*texture);
    sprite->setScale(0.5f,0.5f);
}

void FertBucket::draw(sf::RenderTarget *window)
{
    window->draw(*sprite);
}

/*----------------------------*/