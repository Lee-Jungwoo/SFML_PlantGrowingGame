#ifndef PLANT_H
#define PLANT_H
#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Buckets.h"

#define PLANT_LEVEL 4

enum class PlantSpecies;

class Plant
{
private:
    bool handled;
    int elapsedDay;
    int level; // 1 ~ 4까지 있음
    int waterPercentage;
    int soilPercentage;

    int price;

    PlantSpecies species;
    int bloomingDay;
    sf::Texture *plantTexture[PLANT_LEVEL + 1]; // 죽은 것도 load 해야됨.
    sf::Sprite *sprite;

    

public:
    Plant(PlantSpecies);
    ~Plant();

    void fillWater(WaterBucket &);
    void fillEnergy(FertBucket &);
    void skipThisTime();
    bool isHandled() { return handled; };

    sf::Sprite *getSprite();
    PlantSpecies getSpecies();

    int getPrice();

    bool isDead();
    bool isBlooming();
    void update();
    void draw(sf::RenderTarget &target);
    int getPercentage();
    int getwaterPercentage();
    int getSoilpercentage();

    /*
    DEBUGGING-------------
    */
    void kill();
    void bloom();
};

class PlantSlot
{
private:
    Plant *plant;

    sf::Texture slotTexture;
    sf::Sprite *sprite;

public:
    PlantSlot();

    void pushPlant(Plant *p);
    void pullPlant();
    bool isEmpty();
    Plant *getPlant(); // 메인 화면에서 쓸거

    sf::Sprite *getSprite();

    void draw(sf::RenderTarget &target);

    /*
     *DEBUGGING---------------------
     */
};

#endif