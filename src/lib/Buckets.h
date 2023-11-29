#include <SFML/Graphics.hpp>
#ifndef BUCKET_H
#define BUCKET_H

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
};

class FertBucket : public Bucket
{
public:
    FertBucket();
    void draw(sf::RenderTarget *) override;
};

#endif