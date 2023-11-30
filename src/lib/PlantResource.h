#ifndef PLANTRESOURCE_H
#define PLANTRESOURCE_H
#include "State.h"
#include <vector>
#include <map>

enum PlantSpecies {A , B,C};

class PlantResource{
private:
    static std::map<PlantSpecies, int> bloomingDay;
    
    static std::map<Stage, std::vector<PlantSpecies>> plantByStage;

public:
    static int getBloomingDay(PlantSpecies plantSpecies);

    static std::vector<PlantSpecies> getPlantsByStage(Stage);


};


#endif