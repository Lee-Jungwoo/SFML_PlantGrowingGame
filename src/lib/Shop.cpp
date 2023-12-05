#include "Shop.h"

Shop::Shop(GameState &state)
{

	currentNumOfPlantsInShop = state.getRemainingPlantsInShop()->size();
	std::vector<PlantSpecies> *plants = state.getRemainingPlantsInShop();

	// this->slot1_t.loadFromFile("../../arrow_left.png");
	// this->slot2_t.loadFromFile("../../arrow_right.png");
	// this->slot3_t.loadFromFile("../../arrow_left.png");
	// this->slot4_t.loadFromFile("../../arrow_right.png");

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_t[i] = *Resource::getTexture((*plants)[i],4);
	}

	this->back_t.loadFromFile("../../yellow_rect.png");
	// this->back2_t.loadFromFile("../../yellow_rect.png");
	// this->back3_t.loadFromFile("../../yellow_rect.png");
	// this->back4_t.loadFromFile("../../yellow_rect.png");

	// this->slot1_s = Sprite(this->slot1_t);
	// this->slot2_s = Sprite(this->slot2_t);
	// this->slot3_s = Sprite(this->slot3_t);
	// this->slot4_s = Sprite(this->slot4_t);

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_s[i] = Sprite(this->slot_t[i]); // Plant sprite init.
		slot_s[i].setScale(0.35f,0.35f); //to make the sprite 70 x 70 size.
	}

	// this->back1_s = Sprite(this->back_t);
	// this->back2_s = Sprite(this->back_t);
	// this->back3_s = Sprite(this->back_t);
	// this->back4_s = Sprite(this->back_t);

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		back_s[i] = Sprite(this->back_t); // Slots of items sprite init.
	}

	for (int i = 0; i < currentNumOfPlantsInShop; i++)
	{
		slot_s[i].setPosition(68, 241 + (i * 120));
		back_s[i].setPosition(41, 230 + (i * 120));
	}

	slot1_s.setPosition(38, 241);
	slot2_s.setPosition(38, 361);
	slot3_s.setPosition(38, 481);
	slot4_s.setPosition(38, 601);

	back1_s.setPosition(68, 230);
	back2_s.setPosition(68, 350);
	back3_s.setPosition(68, 470);
	back4_s.setPosition(68, 590);

	// text1.setFont(font);
	// text1.setCharacterSize(19);
	// text1.setFillColor(sf::Color::Black);
	// text1.setString("Test1");
	// text1.setPosition(270, 147);
	// text1.setStyle(sf::Text::Bold);

	// text2.setFont(font);
	// text2.setCharacterSize(19);
	// text2.setFillColor(sf::Color::Black);
	// text2.setString("Test2");
	// text2.setPosition(270, 279);
	// text2.setStyle(sf::Text::Bold);

	// text3.setFont(font);
	// text3.setCharacterSize(19);
	// text3.setFillColor(sf::Color::Black);
	// text3.setString("Test3");
	// text3.setPosition(270, 411);
	// text3.setStyle(sf::Text::Bold);

	// text4.setFont(font);
	// text4.setCharacterSize(19);
	// text4.setFillColor(sf::Color::Black);
	// text4.setString("Test4");
	// text4.setPosition(270, 543);
	// text4.setStyle(sf::Text::Bold);
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
