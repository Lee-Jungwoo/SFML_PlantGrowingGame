#include "Slot.h"

Slot::Slot()
{
	this->slot_t.loadFromFile("../../slot.png");
	this->slot_s = Sprite(this->slot_t);
	slot_s.setPosition(195, 330);

	arrow_left_t.loadFromFile("../../arrow_left.png");
	arrow_left_s = Sprite(arrow_left_t);
	arrow_left_s.setPosition(23, 345);

	arrow_right_t.loadFromFile("../../arrow_right.png");
	arrow_right_s = Sprite(arrow_right_t);
	arrow_right_s.setPosition(405, 345);

	this->font.loadFromFile("../../Font-Medium.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(33);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("Blank");
	this->text.setPosition(150, 263);
	this->text.setStyle(sf::Text::Bold);
}

int Slot::draw(sf::RenderWindow* window)
{
	window->draw(slot_s);
	window->draw(arrow_left_s);
	window->draw(arrow_right_s);
	window->draw(text);
	return 0;
}

void Slot::mode(int num)
{
	if (num == 1)
	{
		this->slot_t.loadFromFile("../../slot.png");
		this->slot_s = Sprite(this->slot_t);
		slot_s.setPosition(195, 330);

		this->font.loadFromFile("../../Font-Medium.ttf");
		this->text.setFont(font);
		this->text.setCharacterSize(33);
		this->text.setFillColor(sf::Color::Black);
		this->text.setString("Information");
		this->text.setPosition(150, 263);
		this->text.setStyle(sf::Text::Bold);
	}
	else if(num==2)
	{
		this->slot_t.loadFromFile("../../slot2.png");
		this->slot_s = Sprite(this->slot_t);
		slot_s.setPosition(195, 330);

		this->font.loadFromFile("../../Font-Medium.ttf");
		this->text.setFont(font);
		this->text.setCharacterSize(33);
		this->text.setFillColor(sf::Color::Black);
		this->text.setString("Information");
		this->text.setPosition(150, 263);
		this->text.setStyle(sf::Text::Bold);
	}
	else if (num == 3)
	{
		this->slot_t.loadFromFile("../../slot3.png");
		this->slot_s = Sprite(this->slot_t);
		slot_s.setPosition(195, 330);

		this->font.loadFromFile("../../Font-Medium.ttf");
		this->text.setFont(font);
		this->text.setCharacterSize(33);
		this->text.setFillColor(sf::Color::Black);
		this->text.setString("Information");
		this->text.setPosition(150, 263);
		this->text.setStyle(sf::Text::Bold);
	}
	else if (num == 4)
	{
		this->slot_t.loadFromFile("../../slot4.png");
		this->slot_s = Sprite(this->slot_t);
		slot_s.setPosition(195, 330);

		this->font.loadFromFile("../../Font-Medium.ttf");
		this->text.setFont(font);
		this->text.setCharacterSize(33);
		this->text.setFillColor(sf::Color::Black);
		this->text.setString("Information");
		this->text.setPosition(150, 263);
		this->text.setStyle(sf::Text::Bold);
	}
}

