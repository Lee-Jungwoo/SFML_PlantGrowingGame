#include "MainSlot.h"

MainSlot::MainSlot()
{
	slot1_t.loadFromFile("slot.png");
	slot1_s = Sprite(slot1_t);
	slot1_s.setPosition(Slot_x1_m, Slot_y1_m);

	slot2_t.loadFromFile("slot.png");
	slot2_s = Sprite(slot2_t);
	slot2_s.setPosition(Slot_x1_m, Slot_y2_m);

	slot3_t.loadFromFile("slot.png");
	slot3_s = Sprite(slot3_t);
	slot3_s.setPosition(Slot_x2_m, Slot_y1_m);

	slot4_t.loadFromFile("slot.png");
	slot4_s = Sprite(slot4_t);
	slot4_s.setPosition(Slot_x2_m, Slot_y2_m);
}

int MainSlot::draw(sf::RenderWindow* window)
{
	window->draw(slot1_s);
	window->draw(slot2_s);
	window->draw(slot3_s);
	window->draw(slot4_s);

	return 0;
}

void MainSlot::update()
{
}
