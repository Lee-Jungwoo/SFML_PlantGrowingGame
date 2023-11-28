#include "Plant.h"


PlantSlot::PlantSlot() : plant(nullptr){}

bool PlantSlot::isEmpty(){
    if(plant == nullptr){
        return true;
    }
    return false;
}

void PlantSlot::pushPlant(Plant *p){
    this->plant = p;
}

void PlantSlot::pullPlant(){
    this->plant = nullptr;
}