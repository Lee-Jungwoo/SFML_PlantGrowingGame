#include "PlantResource.h"


std::map<PlantSpecies, int> PlantResource::bloomingDay = {
    {A, 24},
    {B, 35},
    {C, 49}
};

int PlantResource::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}