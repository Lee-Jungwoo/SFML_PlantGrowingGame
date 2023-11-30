#ifndef PLANTRESOURCE_H
#define PLANTRESOURCE_H
#include "Plant.h"
#include "State.h"


class PlantResourceContainer{
private:
    static std::map<PlantSpecies, int> bloomingDay;
    
public:
    static int getBloomingDay(PlantSpecies plantSpecies);


};


#endif