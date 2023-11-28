#include <SFML/Graphics.hpp>

class Bucket
{
protected:
    const int capacity = 4;
    int remaining;
    sf::Color color;
    bool isEmpty();

public:
    Bucket() : remaining(4) {}
    void fill() { remaining = 4; }
    bool consume();
    sf::Color getColor();
};


class WaterBucket : Bucket
{
public:
    WaterBucket(){
        color = sf::Color(0,128,255,0);
    }
};


class FertBucket : Bucket
{
public:
    FertBucket(){
        color = sf::Color(255,191,0,0);
    }
};
