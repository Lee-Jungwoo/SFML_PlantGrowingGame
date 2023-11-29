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
    texture = new sf::Texture();
    texture->loadFromFile("../../assets/WaterBucket.png");

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
