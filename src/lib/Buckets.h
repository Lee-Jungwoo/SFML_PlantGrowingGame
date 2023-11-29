#include <SFML/Graphics.hpp>
#ifndef BUCKET_H
#define BUCKET_H

class Bucket
{
protected:
    sf::Image bucketImage[4];
    sf::Sprite sprite;
    sf::Texture * texture;
    const int capacity = 4;
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