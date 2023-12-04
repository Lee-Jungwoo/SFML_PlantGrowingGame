#ifndef BUCKET_H
#define BUCKET_H
#include <SFML/Graphics.hpp>
#define BUCKET_CAPACITY 100

class Bucket
{
protected:
   
    sf::Sprite *sprite;
    sf::Texture * texture;
    
    int remaining;
    bool isEmpty();

public:

    Bucket();
    ~Bucket();
    void fill();
    bool consume();

    sf::Texture * getTexture();
    virtual void draw(sf::RenderTarget *);
    sf::Sprite *getSprite();
    int getRemaining();
    

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