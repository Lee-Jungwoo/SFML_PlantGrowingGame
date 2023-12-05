#include "Minigame.h"

Minigame::Minigame()
{
	this->back1_t.loadFromFile("../../yellow_rect.png");
	this->back2_t.loadFromFile("../../yellow_rect.png");
	this->back3_t.loadFromFile("../../yellow_rect.png");
	this->back4_t.loadFromFile("../../yellow_rect.png");

	this->back1_s = Sprite(this->back1_t);
	this->back2_s = Sprite(this->back2_t);
	this->back3_s = Sprite(this->back3_t);
	this->back4_s = Sprite(this->back4_t);

	back1_s.setPosition(41, 230);
	back2_s.setPosition(41, 350);
	back3_s.setPosition(41, 470);
	back4_s.setPosition(41, 590);

/*
	this->font.loadFromFile("../../Font-Medium.ttf");

	text1.setFont(font);
	text1.setCharacterSize(19);
	text1.setFillColor(sf::Color::Black);
	text1.setString("Game1");
	text1.setPosition(270, 147);
	text1.setStyle(sf::Text::Bold);

	text2.setFont(font);
	text2.setCharacterSize(19);
	text2.setFillColor(sf::Color::Black);
	text2.setString("Game2");
	text2.setPosition(270, 279);
	text2.setStyle(sf::Text::Bold);

	text3.setFont(font);
	text3.setCharacterSize(19);
	text3.setFillColor(sf::Color::Black);
	text3.setString("Game3");
	text3.setPosition(270, 411);
	text3.setStyle(sf::Text::Bold);

	text4.setFont(font);
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Black);
	text4.setString("Game4");
	text4.setPosition(270, 543);
	text4.setStyle(sf::Text::Bold);
*/

}

Sprite *Minigame::getSlotSprite(int num)
{
    
}

int Minigame::draw(sf::RenderWindow *window)
{

	window->draw(back1_s);
	window->draw(back2_s);
	window->draw(back3_s);
	window->draw(back4_s);

/*	// window->draw(text1);
	// window->draw(text2);
	// window->draw(text3);
	// window->draw(text4);
*/
	
	return 0;

}
