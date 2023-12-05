#include "Shop.h"

Shop::Shop(GameState &state)
{

	currentNumOfPlantsInShop = state.getRemainingPlantsInShop()->size();
	std::vector<PlantSpecies> *plants = state.getRemainingPlantsInShop();



	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_t[i] = *Resource::getTexture((*plants)[i],4);
	}

	this->back_t.loadFromFile("../../yellow_rect.png");


	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_s[i] = Sprite(this->slot_t[i]); // Plant sprite init.
		slot_s[i].setScale(0.35f,0.35f); //to make the sprite 70 x 70 size.
	}


	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		back_s[i] = Sprite(this->back_t); // Slots of items sprite init.
	}

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_s[i].setPosition(68, 241 + (i * 120));
		back_s[i].setPosition(41, 230 + (i * 120));
	}

}

int Shop::draw(sf::RenderWindow *window, GameState &state)
{

	// window->draw(text1);
	// window->draw(text2);
	// window->draw(text3);
	// window->draw(text4);

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		window->draw(back_s[i]);
		window->draw(slot_s[i]);
	}

	return 0;
}

Sprite *Shop::getSlotSprite(int num)
{
	return &this->back_s[num - 1];
}
