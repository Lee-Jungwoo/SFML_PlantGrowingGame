#include "MainSlot.h"
#define PLANT_SLOT_PATH "../../assets/PlantSlot.png"

MainSlot::MainSlot(GameState &state)
{
	int currentNumberOfPlant = state.getSlotNum();

	slot_t.loadFromFile(PLANT_SLOT_PATH);

	slot_s[0] = Sprite(slot_t);
	slot_s[1] = Sprite(slot_t);
	slot_s[2] = Sprite(slot_t);
	slot_s[3] = Sprite(slot_t);

	slot_s[0].setPosition(Slot_x1_m, Slot_y1_m);
	slot_s[1].setPosition(Slot_x2_m, Slot_y1_m);
	slot_s[2].setPosition(Slot_x1_m, Slot_y2_m);
	slot_s[3].setPosition(Slot_x2_m, Slot_y2_m);

	for (int i = 0; i < currentNumberOfPlant; i++)
	{
		plant_s[i] = *state.getPlantSlot(i)->getPlant()->getSprite();
		plant_s[i].setPosition(83 + (i % 2) * 254, 277 + (i > 1) * 245);
		plant_s[i].setScale(0.6f, 0.6f);
	}
}

int MainSlot::draw(sf::RenderWindow *window, GameState &state)
{
	for (int i = 0; i < 4; i++)
	{
		window->draw(slot_s[i]);
	}

	for (int i = 0; i < 4; i++)
	{

		if (!state.getPlantSlot(i)->isEmpty())
		{
			std::cout << "drawing plants on the main page: " + std::to_string(i + 1) << std::endl;
			window->draw(plant_s[i]);
		}
		else
		{
			std::cout << "EMPTY Slot: "<< i+1 << std::endl;
		}
	}

	return 0;
}

void MainSlot::update()
{
}

Sprite *MainSlot::getSprite(int a)
{
	return &slot_s[a - 1];
}
