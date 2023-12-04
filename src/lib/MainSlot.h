#ifndef MAINSLOT_H
#define MAINSLOT_H
#include <SFML/Graphics.hpp>

#define Slot_x1_m 43
// #define Slot_x1_M 225
#define Slot_x2_m 297
// #define Slot_x2_M 465
#define Slot_y1_m 237
// #define Slot_y1_M 413
#define Slot_y2_m 482
// #define Slot_y2_M 638
using namespace sf;
class MainSlot
{
private:
	Texture slot_t;


	Sprite slot1_s;
	Sprite slot2_s;
	Sprite slot3_s;
	Sprite slot4_s;

	Sprite slot_s[4];
public:
	MainSlot();
	~MainSlot() {}
	int draw(RenderWindow* window);
	void update();

	Sprite * getSprite(int); // 1~4
};
#endif // !MAINSLOT_H
