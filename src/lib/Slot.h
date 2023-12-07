#ifndef SLOT_H
#define SLOT_H
#include <SFML/Graphics.hpp>
#include "State.h"

using namespace sf;
class Slot
{
private:
	Texture slot_t;
	Sprite slot_s;

	Texture arrow_left_t;
	Sprite arrow_left_s;

	Texture arrow_right_t;
	Sprite arrow_right_s;

	Texture water_t;
	Sprite water_s;

	Texture fert_t;
	Sprite fert_s;

	Texture skip_t;
	Sprite skip_s;

	Sprite plant_s;


	Text text;
	Font font;

	Plant *p;
	bool empty;

public:
	Slot();
	~Slot() {}
	int draw(sf::RenderWindow *);
	void mode(int, GameState &);

	Sprite *getLeftArrowSprite();
	Sprite *getRightArrowSprite();
	Sprite *getWaterButtonSprite();
	Sprite *getFertButtonSprite();
	Sprite *getSkipButtonSprite();
};
#endif // !SLOT_H
