#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Buckets.h"
#include "Plant.h"
#include "Resource.h"
#include "State.h"

using namespace sf;

class Game{
private:

    GameState gameState;


public:
    void nextDay();

};

#endif