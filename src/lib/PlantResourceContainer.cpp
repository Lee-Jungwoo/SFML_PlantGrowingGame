#include "PlantResourceContainer.h"

//-------------------------------

/**
 *  PlantResourceContainer
 *
 */
std::map<PlantSpecies, int> PlantResourceContainer::bloomingDay = {
    {A, 24},
    {B, 35},
    {C, 49}
};

int PlantResourceContainer::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}