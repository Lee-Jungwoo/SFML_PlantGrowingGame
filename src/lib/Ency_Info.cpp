#include "Ency_Info.h"

EncyclopediaInfoView::EncyclopediaInfoView()
{
    slot_t.loadFromFile("../../slot.png");
    slot_s = Sprite(slot_t);
    slot_s.setPosition(135, 315);

    arrow_left_t.loadFromFile("../../arrow_left.png");
    arrow_left_s = Sprite(arrow_left_t);
    arrow_left_s.setPosition(19, 415);

    arrow_right_t.loadFromFile("../../arrow_right.png");
    arrow_right_s = Sprite(arrow_right_t);
    arrow_right_s.setPosition(451, 415);

    

	this->font.loadFromFile("../../assets/Fonts/Font-Medium.ttf");
	this->infoText.setFont(font);
	this->infoText.setCharacterSize(16);
	this->infoText.setFillColor(sf::Color::White);
	this->infoText.setString("Blank");
	this->infoText.setPosition(31, 100);
	this->infoText.setLineSpacing(1);
	this->infoText.setStyle(sf::Text::Bold);
}

int EncyclopediaInfoView::draw(sf::RenderWindow *window)
{
    window->draw(slot_s);
    window->draw(plant_s);
    window->draw(arrow_left_s);
    window->draw(arrow_right_s);

    window->draw(infoText);

    return 0;
}

void EncyclopediaInfoView::changeMode(PlantSpecies species)
{
    delete plant_s.getTexture();
    plant_s = Sprite(*Resource::getTexture(species,4));
    plant_s.setPosition(210,390);
    plant_s.setScale(0.6f, 0.6f);

    infoText.setString(Resource::getInfo(species));
}

Sprite *EncyclopediaInfoView::getLeftArrowSprite()
{
    return &arrow_left_s;
}

Sprite *EncyclopediaInfoView::getRightArrowSprite()
{
    return &arrow_right_s;
}
