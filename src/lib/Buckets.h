#include <SFML/Graphics.hpp>

class Bucket
{
protected:
    const int capacity = 4;
    int remaining;
    const sf::Color color = sf::Color(0, 0, 0, 0);
    bool isEmpty() { return !static_cast<bool>(remaining); }

public:
    Bucket() : remaining(4) {}
    void fill() { remaining = 4; }
    bool consume();
};

class WaterBucket : Bucket
{
public:
};

class FertBucket : Bucket
{
public:
};
