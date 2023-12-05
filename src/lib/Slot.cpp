#include "Slot.h"

Slot::Slot()
{
	this->slot_t.loadFromFile("../../slot.png");
	this->slot_s = Sprite(this->slot_t);
	slot_s.setPosition(135, 349);

	arrow_left_t.loadFromFile("../../arrow_left.png");
	arrow_left_s = Sprite(arrow_left_t);
	arrow_left_s.setPosition(19, 449);

	arrow_right_t.loadFromFile("../../arrow_right.png");
	arrow_right_s = Sprite(arrow_right_t);
	arrow_right_s.setPosition(451, 449);

	water_t.loadFromFile("../../water.png");
	fert_t.loadFromFile("../../fert.png");
	skip_t.loadFromFile("../../skip.png");

	water_s = Sprite(water_t);
	fert_s = Sprite(fert_t);
	skip_s = Sprite(skip_t);

	water_s.setPosition(42.f, 640.f);
	fert_s.setPosition(210.f, 640.f);
	skip_s.setPosition(378.f, 640.f);

	this->font.loadFromFile("../../Font-Medium.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("Blank");
	this->text.setPosition(31, 154);
	this->text.setLineSpacing(1);
	this->text.setStyle(sf::Text::Bold);

	empty = true;
}

int Slot::draw(sf::RenderWindow *window)
{
	window->draw(slot_s);
	window->draw(arrow_left_s);
	window->draw(arrow_right_s);

	if (!empty)
	{
		window->draw(text);
		window->draw(water_s);
		window->draw(fert_s);
		window->draw(skip_s);
	}
	return 0;
}

void Slot::mode(int num, GameState &state)
{
	int plantSlotIdx = num - 1;

	if (state.getPlantSlot(plantSlotIdx)->isEmpty())
		empty = true;
	else
	{
		empty = false;
		p = state.getPlantSlot(plantSlotIdx)->getPlant();

		std::string infoString = "Blooming status: ";

		infoString += std::to_string(p->getPercentage());
		infoString += std::string("\nWater: ") + std::to_string(p->getwaterPercentage());
		infoString += std::string("\nEnergy: ") + std::to_string(p->getSoilpercentage());

		this->text.setString(infoString);
	}
}

Sprite *Slot::getLeftArrowSprite()
{
	return &arrow_left_s;
}

Sprite *Slot::getRightArrowSprite()
{
	return &arrow_right_s;
}

Sprite *Slot::getWaterButtonSprite()
{
    return &water_s;
}

Sprite *Slot::getFertButtonSprite()
{
    return &fert_s;
}

Sprite *Slot::getSkipButtonSprite()
{
    return &skip_s;
}
