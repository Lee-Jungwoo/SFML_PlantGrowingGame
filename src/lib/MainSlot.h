#ifndef MAINSLOT_H
#define MAINSLOT_H
#include <SFML/Graphics.hpp>

#define Slot_x1_m 75
#define Slot_x1_M 225
#define Slot_x2_m 315
#define Slot_x2_M 465
#define Slot_y1_m 263
#define Slot_y1_M 413
#define Slot_y2_m 488
#define Slot_y2_M 638
using namespace sf;
class MainSlot
{
private:
	Texture slot1_t;
	Texture slot2_t;
	Texture slot3_t;
	Texture slot4_t;

	Sprite slot1_s;
	Sprite slot2_s;
	Sprite slot3_s;
	Sprite slot4_s;
public:
	MainSlot();
	~MainSlot() {}
	int draw(RenderWindow* window);
	void update();
};
#endif // !MAINSLOT_H
