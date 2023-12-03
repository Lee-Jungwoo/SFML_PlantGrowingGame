#include "Resource.h"
#include <string>
#include <iostream>
std::map<Stage, std::vector<PlantSpecies> *> Resource::plantByStage = {

    {Stage::Desert,
     new std::vector<PlantSpecies>{
         PlantSpecies::Carrot,
         PlantSpecies::Millet,
         PlantSpecies::Oat,
         PlantSpecies::Yacon}},

    {Stage::Temperate,
     new std::vector<PlantSpecies>{
         PlantSpecies::Lettuce,
         PlantSpecies::Strawberry,
         PlantSpecies::Tomato}},

    {Stage::Tropical,
     new std::vector<PlantSpecies>{
         PlantSpecies::Corn,
         PlantSpecies::Pepper,
         PlantSpecies::Potato,
         PlantSpecies::Tropical_Flower}}};

std::map<PlantSpecies, int> Resource::bloomingDay = {
    {PlantSpecies::Carrot, 10},
    {PlantSpecies::Millet, 10},
    {PlantSpecies::Oat, 10},
    {PlantSpecies::Yacon, 10},
    {PlantSpecies::Lettuce, 10},
    {PlantSpecies::Strawberry, 10},
    {PlantSpecies::Tomato, 10},
    {PlantSpecies::Corn, 10},
    {PlantSpecies::Pepper, 10},
    {PlantSpecies::Potato, 10},
    {PlantSpecies::Tropical_Flower, 10}};

std::map<PlantSpecies, int> price = {
    {PlantSpecies::Carrot, 1000},
    {PlantSpecies::Millet, 1000},
    {PlantSpecies::Oat, 1000},
    {PlantSpecies::Yacon, 1000},
    {PlantSpecies::Lettuce, 1000},
    {PlantSpecies::Strawberry, 1000},
    {PlantSpecies::Tomato, 1000},
    {PlantSpecies::Corn, 1000},
    {PlantSpecies::Pepper, 1000},
    {PlantSpecies::Potato, 1000},
    {PlantSpecies::Tropical_Flower, 1000}};

std::map<PlantSpecies, std::string> Resource::speciesName = {
    {PlantSpecies::Carrot, "Carrot"},
    {PlantSpecies::Millet, "Millet"},
    {PlantSpecies::Oat, "Oat"},
    {PlantSpecies::Yacon, "Yacon"},
    {PlantSpecies::Lettuce, "Lettuce"},
    {PlantSpecies::Strawberry, "Strawberry"},
    {PlantSpecies::Tomato, "Tomato"},
    {PlantSpecies::Corn, "Corn"},
    {PlantSpecies::Pepper, "Pepper"},
    {PlantSpecies::Potato, "Potato"},
    {PlantSpecies::Tropical_Flower, "Tropical Flower"}};

int Resource::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}

std::vector<PlantSpecies> *Resource::getPlantsByStage(Stage stage)
{
    return plantByStage[stage];
}

std::string Resource::getName(PlantSpecies plantSpecies)
{
    return speciesName[plantSpecies];
}

std::string Resource::getStageByPlant(PlantSpecies s)
{
    std::vector<PlantSpecies> *v;

    v = plantByStage[Stage::Desert];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Desert";
        }
    }

    v = plantByStage[Stage::Temperate];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Temperate";
        }
    }

    v = plantByStage[Stage::Tropical];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Desert";
        }
    }

    return nullptr;
}

int Resource::getPrice(PlantSpecies s)
{
    return price[s];
}

sf::Texture Resource::getTexture(PlantSpecies s, int level)
{
    std::string filePath = "../../assets/";
    std::string plantName = Resource::getName(s);
    std::string stageName = Resource::getStageByPlant(s);

    if (level > 0)
    {
        filePath = filePath + "/" + stageName + "/" + plantName + "_" + std::to_string(level);
    }else if(level == 0){
        filePath = filePath + "/" + stageName + "/" + plantName + "_Dead";
    }else {
        std::cout<<"ERROR: undefined argument value of 'level' in Resource::getTexture()"<<std::endl;
    }
    
    sf::Texture t;
    if (!t.loadFromFile(filePath))
    {
        std::cout << "ERROR While fetching images." << std::endl;
    }
    return t;
}
