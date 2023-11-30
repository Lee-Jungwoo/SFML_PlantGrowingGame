#include "PlantResource.h"

std::map<Stage, std::vector<PlantSpecies>> PlantResource::plantByStage = {
    {Stage::A, {PlantSpecies::A}}
};


std::map<PlantSpecies, int> PlantResource::bloomingDay = {
    {A, 24},
    {B, 35},
    {C, 49}
};

int PlantResource::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}

std::vector<PlantSpecies> PlantResource::getPlantsByStage(Stage stage)
{
    return plantByStage[stage];
}
