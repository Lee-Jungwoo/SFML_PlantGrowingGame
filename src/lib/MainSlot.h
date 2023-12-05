#ifndef MAINSLOT_H
#define MAINSLOT_H
#include <SFML/Graphics.hpp>
#include "State.h"

#define Slot_x1_m 43
#define Slot_x2_m 297
#define Slot_y1_m 237
#define Slot_y2_m 482

using namespace sf;
class MainSlot
{
private:
	Texture slot_t;

	Sprite slot_s[4];

	Sprite plant_s[4];

public:
	MainSlot(GameState &);
	~MainSlot() {}
	int draw(RenderWindow *window, GameState &state);
	void update();

	Sprite *getSprite(int); // 1~4
};
#endif // !MAINSLOT_H
