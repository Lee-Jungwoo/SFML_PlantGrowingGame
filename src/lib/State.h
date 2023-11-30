#ifndef STATE_H
#define STATE_H
#include <vector>

enum class PlantSpecies;
class PlantResource;

enum class Stage
{
    A,
    B,
    C,
    D
};

class GameState
{
private:
    int day;
    Stage currentStage;
    std::vector<PlantSpecies> * plantsOfCurrentStage;
public:
    void update();
};

#endif
