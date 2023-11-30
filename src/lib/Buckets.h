#ifndef BUCKET_H
#define BUCKET_H
#include <SFML/Graphics.hpp>
#include "Plant.h"

#define BUCKET_CAPACITY 4


class Bucket
{
protected:
    sf::Image bucketImage[BUCKET_CAPACITY];
    sf::Sprite sprite;
    sf::Texture * texture;
    
    int remaining;
    sf::Color color;
    bool isEmpty();

public:

    Bucket();
    ~Bucket();
    void fill();
    bool consume();
    sf::Color getColor();
    sf::Texture * getTexture();
    virtual void draw(sf::RenderTarget *);


};

class WaterBucket : public Bucket
{
private:
    
public:
    WaterBucket();
    void draw(sf::RenderTarget *) override;

    void waterTo(Plant & plant);
};

class FertBucket : public Bucket
{
public:
    FertBucket();
    void draw(sf::RenderTarget *) override;

    void feedTo(Plant &plant);
};

#endif