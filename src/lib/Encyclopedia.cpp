#include"Encyclopedia.h"

Encyclopedia::Encyclopedia() {
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

	slot1_s.setPosition(50, 196);
	slot2_s.setPosition(50, 372);
	slot3_s.setPosition(50, 548);
	slot4_s.setPosition(50, 724);

	back1_s.setPosition(10, 191);
	back2_s.setPosition(10, 367);
	back3_s.setPosition(10, 543);
	back4_s.setPosition(10, 719);

	text1.setFont(font);
	text1.setCharacterSize(25);
	text1.setFillColor(sf::Color::Black);
	text1.setString("Information1");
	text1.setPosition(360, 196);
	text1.setStyle(sf::Text::Bold);

	text2.setFont(font);
	text2.setCharacterSize(25);
	text2.setFillColor(sf::Color::Black);
	text2.setString("Information2");
	text2.setPosition(360, 372);
	text2.setStyle(sf::Text::Bold);

	text3.setFont(font);
	text3.setCharacterSize(25);
	text3.setFillColor(sf::Color::Black);
	text3.setString("Information3");
	text3.setPosition(360, 548);
	text3.setStyle(sf::Text::Bold);

	text4.setFont(font);
	text4.setCharacterSize(25);
	text4.setFillColor(sf::Color::Black);
	text4.setString("Information4");
	text4.setPosition(360, 724);
	text4.setStyle(sf::Text::Bold);

}

int Encyclopedia::draw(sf::RenderWindow* window)
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
