#include "PlantResource.h"

std::map<Stage, std::vector<PlantSpecies> *> PlantResource::plantByStage = {
    {Stage::A, new std::vector<PlantSpecies>{PlantSpecies::A}},
    {Stage::B, new std::vector<PlantSpecies>{PlantSpecies::B}}

};


std::map<PlantSpecies, int> PlantResource::bloomingDay = {
    {PlantSpecies::A, 24},
    {PlantSpecies::B, 35},
    {PlantSpecies::C, 49}
};

int PlantResource::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}

std::vector<PlantSpecies> * PlantResource::getPlantsByStage(Stage stage)
{
    return plantByStage[stage];
}
