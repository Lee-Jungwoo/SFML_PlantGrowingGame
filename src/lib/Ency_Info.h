#ifndef ENCY_INFO_H
#define ENCY_INFO_H

#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "State.h"
#include "Resource.h"

using namespace sf;
class EncyclopediaInfoView
{
private:
	Texture slot_t;
	Sprite slot_s;

	Texture arrow_left_t;
	Sprite arrow_left_s;

	Texture arrow_right_t;
	Sprite arrow_right_s;

    Sprite plant_s;

	Text infoText;
	Font font;

	Plant *p;

	bool empty;

public:
	EncyclopediaInfoView();

	~EncyclopediaInfoView() {}
	int draw(sf::RenderWindow *);
	void changeMode(PlantSpecies);
    

	Sprite *getLeftArrowSprite();
  
	Sprite *getRightArrowSprite();

};

#endif