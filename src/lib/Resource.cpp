#include "Resource.h"
#include <string>

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
    {PlantSpecies::Carrot, 1},
    {PlantSpecies::Millet, 1},
    {PlantSpecies::Oat, 1},
    {PlantSpecies::Yacon, 1},
    {PlantSpecies::Lettuce, 1},
    {PlantSpecies::Strawberry, 1},
    {PlantSpecies::Tomato, 1},
    {PlantSpecies::Corn, 1},
    {PlantSpecies::Pepper, 1},
    {PlantSpecies::Potato, 1},
    {PlantSpecies::Tropical_Flower, 1}};

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
