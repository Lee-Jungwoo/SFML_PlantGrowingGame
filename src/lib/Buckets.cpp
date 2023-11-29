#include "Buckets.h"

Bucket::Bucket()
{
    remaining = 4;
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
        //사진 바꾸는 코드
        return true;
    }

}

void Bucket::fill(){
    remaining = 4;
    //사진 원래대로 돌리는 코드
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
    return new sf::Texture(*texture);
}

WaterBucket::WaterBucket()
{

    bucketImage[0].loadFromFile("../../assets/WaterBucket.png");
    // bucketImage[1].loadFromFile();
    // bucketImage[2].loadFromFile();
    // bucketImage[3].loadFromFile();

    texture = new sf::Texture();
    texture->loadFromImage(bucketImage[0]);

    

    sprite.setPosition(sf::Vector2f(300.f, 10.f));
    sprite.setTexture(*texture);
    sprite.setScale(0.4, 0.4);
}

void WaterBucket::draw(sf::RenderTarget *window)
{

    window->draw(sprite);
}

FertBucket::FertBucket()
{
    texture = new sf::Texture();
    texture->loadFromFile("../../assets/FertBucket.png");
    sprite.setPosition(sf::Vector2f(400.f, 10.f));
    sprite.setTexture(*texture);
    sprite.setScale(0.4, 0.4);
}

void FertBucket::draw(sf::RenderTarget *window)
{

    window->draw(sprite);
}
