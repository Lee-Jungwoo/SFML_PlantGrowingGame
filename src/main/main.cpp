#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../lib/Game.h"




using namespace sf;
int main()
{
    Game game;

    game.init();
    game.start();

    return 0;
}