#ifndef MINIGAME_H
#define MINIGAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "mini_game_HM_1.h"
#include "mini_game_HM_2.h"
#include "mini_game_JS.cpp"
#include "State.h"

using namespace sf;
class Minigame  {
private:
	Texture back1_t;
	Texture back2_t;
	Texture back3_t;
	Texture back4_t;

	
	Sprite back1_s;
	Sprite back2_s;
	Sprite back3_s;
	Sprite back4_s;

	// Text text1;
	// Text text2;
	// Text text3;
	// Text text4;

	// Font font;
public:
	Minigame();
	~Minigame() {}
	Sprite * getSlotSprite(int num);
    bool startGame(int num, sf::RenderWindow *window, GameState &state);
    int draw(sf::RenderWindow *window);


};
#endif // !MINIGAME_H
