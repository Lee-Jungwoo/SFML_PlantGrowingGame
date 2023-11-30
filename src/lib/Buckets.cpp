#include "Buckets.h"
#include "Plant.h"
#include <iostream>



/**
 *         BUCKET              
 * */
Bucket::Bucket()
{
    remaining = BUCKET_CAPACITY - 1;
}

Bucket::~Bucket()
{
    delete texture;
}

bool Bucket::consume()
{

    if (this->isEmpty())
    {
        return false;
    }
    else
    {
        remaining--;
        delete texture;
        texture = new sf::Texture();
        texture->loadFromImage(bucketImage[remaining]);
        sprite.setTexture(*texture, true);
        std::cout << remaining << std::endl;
        return true;
    }
}

void Bucket::fill()
{
    remaining = BUCKET_CAPACITY - 1;
    delete texture;
    texture = new sf::Texture();
    texture->loadFromImage(bucketImage[remaining]);
    sprite.setTexture(*texture, true);
    std::cout << remaining << std::endl;
}

void Bucket::draw(sf::RenderTarget *window)
{
    window->draw(sf::Sprite(*texture));
}

bool Bucket::isEmpty()
{
    return !static_cast<bool>(remaining);
}

sf::Color Bucket::getColor()
{
    return color;
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
    /**
     * 이거 나중에 for문 돌려놓기
     */
    bucketImage[3].loadFromFile("../../assets/WaterBucket.png");
    bucketImage[2].loadFromFile("../../assets/Logo.png");
    bucketImage[1].loadFromFile("../../assets/FertBucket.png");
    // bucketImage[0].loadFromFile();

    texture = new sf::Texture();
    texture->loadFromImage(bucketImage[BUCKET_CAPACITY - 1]);

    sprite.setPosition(sf::Vector2f(300.f, 10.f));
    sprite.setTexture(*texture, true);
}

void WaterBucket::draw(sf::RenderTarget *window)
{
    window->draw(sprite);
}

void WaterBucket::waterTo(Plant &plant)
{
}

void water(Plant &plant){

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
    // bucketImage[3].loadFromFile("../../assets/WaterBucket.png");
    // bucketImage[2].loadFromFile("../../assets/Logo.png");
    // bucketImage[1].loadFromFile("../../assets/FertBucket.png");
    // bucketImage[0].loadFromFile();

    texture = new sf::Texture();
    texture->loadFromImage(bucketImage[BUCKET_CAPACITY - 1]);

    sprite.setPosition(sf::Vector2f(400.f, 10.f));
    sprite.setTexture(*texture);

}

void FertBucket::draw(sf::RenderTarget *window)
{
    window->draw(sprite);
}
/*----------------------------*/