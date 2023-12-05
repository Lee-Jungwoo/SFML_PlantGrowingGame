#ifndef SHOP_H
#define SHOP_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Resource.h"
using namespace sf;

class Shop
{
private:
	Texture slot1_t;
	Texture slot2_t;
	Texture slot3_t;
	Texture slot4_t;

	Texture slot_t[4];

	Texture back_t;
	// Texture back2_t;
	// Texture back3_t;
	// Texture back4_t;

	Sprite slot1_s;
	Sprite slot2_s;
	Sprite slot3_s;
	Sprite slot4_s;

	Sprite slot_s[4];

	Sprite back1_s;
	Sprite back2_s;
	Sprite back3_s;
	Sprite back4_s;

	Sprite back_s[4];

	Text text1;
	Text text2;
	Text text3;
	Text text4;

	Text text[4];

	Font font;

	int currentNumOfPlantsInShop;

public:
	Shop(GameState &);
	~Shop() {}
	int draw(sf::RenderWindow *window, GameState &);
	Sprite *getSlotSprite(int);
};
#endif // !SHOP_H
