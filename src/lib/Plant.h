#ifndef PLANT_H
#define PLANT_H
#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#define PLANT_LEVEL 4

enum PlantSpecies {A , B,C};

class Plant
{
private:
    int elapsedDay;
    int level;
    int waterPercentage;
    int soilPercentage;
    PlantSpecies species;
    int bloomingDay;
    sf::Texture plantTexture[PLANT_LEVEL];
    sf::Sprite sprite;

public:
    Plant(PlantSpecies);
    ~Plant();

    void fillWater();
    void fillEnergy();
    
    

    bool isDead();
    bool isBlooming();
    void draw(sf::RenderTarget & target);

};



class PlantSlot
{
private:
    Plant *plant;
    bool isEmpty();

public:
    PlantSlot();

    void pushPlant(Plant *p);
    void pullPlant();
};

#endif 