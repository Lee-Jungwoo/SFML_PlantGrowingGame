#ifndef PLANTRESOURCE_H
#define PLANTRESOURCE_H
#include "State.h"
#include <vector>
#include <map>
#include <string>

enum class Stage;

enum class PlantSpecies {A = 0, B,C};

class PlantResource{
private:
    static std::map<PlantSpecies, int> bloomingDay;
    static std::map<PlantSpecies, std::string> speciesName;
    static std::map<Stage, std::vector<PlantSpecies> *> plantByStage;
    

public:
    static int getBloomingDay(PlantSpecies plantSpecies);
    static std::vector<PlantSpecies> * getPlantsByStage(Stage);
    static std::string getName(PlantSpecies plantSpecies);

};


#endif