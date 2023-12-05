#ifndef RESOURCE_H
#define RESOURCE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>

enum class Stage{
    Desert,
    Temperate,
    Tropical
};
enum class PlantSpecies
{
    Carrot,
    Millet,
    Oat,
    Yacon,
    Cabbage,
    Strawberry,
    Tomato,
    Watermelon,
    Corn,
    Pepper,
    Potato,
    Tropical_Flower
};





class Resource{
private:
    static std::map<PlantSpecies, int> bloomingDay;
    static std::map<PlantSpecies, int> price;
    static std::map<PlantSpecies, std::string> speciesName;
    static std::map<PlantSpecies, std::string> speciesInfo;


    static std::map<Stage, std::vector<PlantSpecies> *> plantByStage;
    

public:
    static int getBloomingDay(PlantSpecies plantSpecies);
    static std::vector<PlantSpecies> * getPlantsByStage(Stage);
    static std::string getName(PlantSpecies plantSpecies);
    static std::string getStageByPlant(PlantSpecies);
    static int getPrice(PlantSpecies);
    static sf::Texture *getTexture(PlantSpecies, int);
    static std::string getInfo(PlantSpecies);
};


#endif