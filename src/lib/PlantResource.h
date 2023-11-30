#ifndef PLANTRESOURCE_H
#define PLANTRESOURCE_H
#include "State.h"
#include <vector>
#include <map>

enum PlantSpecies {A , B,C};

class PlantResource{
private:
    static std::map<PlantSpecies, int> bloomingDay;
    
    static std::map<stage, std::vector<PlantSpecies>> stage_plant;
public:
    static int getBloomingDay(PlantSpecies plantSpecies);


};


#endif