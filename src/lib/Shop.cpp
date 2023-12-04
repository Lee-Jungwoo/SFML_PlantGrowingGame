#include "Shop.h"

Shop::Shop()
{
	this->slot1_t.loadFromFile("../../arrow_left.png");
	this->slot2_t.loadFromFile("../../arrow_right.png");
	this->slot3_t.loadFromFile("../../arrow_left.png");
	this->slot4_t.loadFromFile("../../arrow_right.png");

	this->back1_t.loadFromFile("../../yellow_rect.png");
	this->back2_t.loadFromFile("../../yellow_rect.png");
	this->back3_t.loadFromFile("../../yellow_rect.png");
	this->back4_t.loadFromFile("../../yellow_rect.png");

	this->slot1_s = Sprite(this->slot1_t);
	this->slot2_s = Sprite(this->slot2_t);
	this->slot3_s = Sprite(this->slot3_t);
	this->slot4_s = Sprite(this->slot4_t);

	this->back1_s = Sprite(this->back1_t);
	this->back2_s = Sprite(this->back2_t);
	this->back3_s = Sprite(this->back3_t);
	this->back4_s = Sprite(this->back4_t);

	slot1_s.setPosition(38, 147);
	slot2_s.setPosition(38, 279);
	slot3_s.setPosition(38, 411);
	slot4_s.setPosition(38, 543);

	back1_s.setPosition(8, 143);
	back2_s.setPosition(8, 275);
	back3_s.setPosition(8, 407);
	back4_s.setPosition(8, 539);

	text1.setFont(font);
	text1.setCharacterSize(19);
	text1.setFillColor(sf::Color::Black);
	text1.setString("Test1");
	text1.setPosition(270, 147);
	text1.setStyle(sf::Text::Bold);

	text2.setFont(font);
	text2.setCharacterSize(19);
	text2.setFillColor(sf::Color::Black);
	text2.setString("Test2");
	text2.setPosition(270, 279);
	text2.setStyle(sf::Text::Bold);

	text3.setFont(font);
	text3.setCharacterSize(19);
	text3.setFillColor(sf::Color::Black);
	text3.setString("Test3");
	text3.setPosition(270, 411);
	text3.setStyle(sf::Text::Bold);

	text4.setFont(font);
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Black);
	text4.setString("Test4");
	text4.setPosition(270, 543);
	text4.setStyle(sf::Text::Bold);
}

int Shop::draw(sf::RenderWindow* window)
{
	window->draw(back1_s);
	window->draw(back2_s);
	window->draw(back3_s);
	window->draw(back4_s);

	window->draw(this->slot1_s);
	window->draw(this->slot2_s);
	window->draw(this->slot3_s);
	window->draw(this->slot4_s);

	window->draw(text1);
	window->draw(text2);
	window->draw(text3);
	window->draw(text4);

	return 0;
}
