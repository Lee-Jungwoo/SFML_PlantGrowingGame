#ifndef PLANT_H
#define PLANT_H
#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


#define PLANT_LEVEL 4

enum class PlantSpecies;


class Plant
{
private:
    int elapsedDay;
    int level; //1 ~ 4까지 있음
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
    
    sf::Sprite getSprite();
    PlantSpecies getSpecies();

    bool isDead();
    bool isBlooming();
    void update();
    void draw(sf::RenderTarget & target);

};



class PlantSlot
{
private:
    Plant *plant;
    bool isEmpty();
    sf::Sprite sprite;
public:
    PlantSlot();

    void pushPlant(Plant *p);
    void pullPlant();

    Plant * getPlant();
    void draw(sf::RenderTarget &target);
};

#endif 