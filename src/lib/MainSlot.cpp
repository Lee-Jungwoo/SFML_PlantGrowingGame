#include "MainSlot.h"
#define PLANT_SLOT_PATH "../../assets/PlantSlot.png"

MainSlot::MainSlot()
{

	slot_t.loadFromFile(PLANT_SLOT_PATH);
	/*
		slot1_s = Sprite(slot_t);
		slot1_s.setPosition(Slot_x1_m, Slot_y1_m);

		slot2_s = Sprite(slot_t);
		slot2_s.setPosition(Slot_x1_m, Slot_y2_m);

		slot3_s = Sprite(slot_t);
		slot3_s.setPosition(Slot_x2_m, Slot_y1_m);

		slot4_s = Sprite(slot_t);
		slot4_s.setPosition(Slot_x2_m, Slot_y2_m);
	*/
	slot_s[0] = Sprite(slot_t);
	slot_s[1] = Sprite(slot_t);
	slot_s[2] = Sprite(slot_t);
	slot_s[3] = Sprite(slot_t);

	slot_s[0].setPosition(Slot_x1_m, Slot_y1_m);
	slot_s[1].setPosition(Slot_x2_m, Slot_y1_m);
	slot_s[2].setPosition(Slot_x1_m, Slot_y2_m);
	slot_s[3].setPosition(Slot_x2_m, Slot_y2_m);
}

int MainSlot::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < 4; i++)
		window->draw(slot_s[i]);

	return 0;
}

void MainSlot::update()
{
}

Sprite *MainSlot::getSprite(int a)
{
	return &slot_s[a - 1];
}
