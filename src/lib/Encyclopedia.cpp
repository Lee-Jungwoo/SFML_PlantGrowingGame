#include "Encyclopedia.h"
#include <algorithm>
Encyclopedia::Encyclopedia(GameState &state, Stage stage)
{

	// text1.setFont(font);
	// text1.setCharacterSize(25);
	// text1.setFillColor(sf::Color::Black);
	// text1.setString("Information1");
	// text1.setPosition(360, 196);
	// text1.setStyle(sf::Text::Bold);

	arrow_left_t.loadFromFile("../../arrow_left.png");
	arrow_left_s = Sprite(arrow_left_t);
	arrow_left_s.setPosition(68, 681);

	arrow_right_t.loadFromFile("../../arrow_right.png");
	arrow_right_s = Sprite(arrow_right_t);
	arrow_right_s.setPosition(403, 681);

	

	/*
	TESTING
	*/
	// currentNumOfPlantsInDict = 4;
	this->stage = stage;

	plantsInCurrentStage = *(state.getPlantBook());
	plantsInCurrentStage.erase(std::remove_if(plantsInCurrentStage.begin(), plantsInCurrentStage.end(), [&](const PlantSpecies &species)
											  { return Resource::getStageByPlant(species) != Resource::getStageName(stage); }),
							   plantsInCurrentStage.end());
	currentNumOfPlantsInDict = plantsInCurrentStage.size();

	// DEBUGGING
	std::cout << "PLATNS CURRENTLY IN THE ENCYCLOPEDIA  ARE:\n";
	for (std::vector<PlantSpecies>::iterator iter = plantsInCurrentStage.begin(); iter != plantsInCurrentStage.end(); iter++)
	{
		std::cout << Resource::getName(*iter) << std::endl;
	}
	// DEBUGGING

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		slot_t[i] = *Resource::getTexture(plantsInCurrentStage[i], 4);
	}

	this->back_t.loadFromFile("../../yellow_rect.png");

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		slot_s[i] = Sprite(this->slot_t[i]); // Plant sprite init.
		slot_s[i].setScale(0.35f, 0.35f);	 // to make the sprite 70 x 70 size.
	}

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		back_s[i] = Sprite(this->back_t); // Slots of items sprite init.
	}

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		slot_s[i].setPosition(68, 241 + (i * 120));
		back_s[i].setPosition(41, 230 + (i * 120));
	}
}

int Encyclopedia::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		window->draw(this->back_s[i]);
	}

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		window->draw(this->slot_s[i]);
	}

	window->draw(arrow_left_s);
	window->draw(arrow_right_s);

	window->draw(text1);
	window->draw(text2);
	window->draw(text3);
	window->draw(text4);

	return 0;
}

std::vector<PlantSpecies> Encyclopedia::getPlantsInCurrentStage()
{
	return plantsInCurrentStage;
}

bool Encyclopedia::nextStage()
{
	switch (stage)
	{
	case Stage::Desert:
		stage = Stage::Temperate;
		return true;

	case Stage::Temperate:
		stage = Stage::Tropical;
		return true;
	case Stage::Tropical:
		stage = Stage::Desert;
		return true;
	}
	
}

bool Encyclopedia::prevStage()
{
	switch (stage)
	{
	case Stage::Desert:
		stage = Stage::Tropical;
		return true;
	case Stage::Temperate:
		stage = Stage::Desert;
		return true;
	case Stage::Tropical:
		stage = Stage::Temperate;
		return true;
	default:
		break;
	}
}

Sprite *Encyclopedia::getLeftArrowSprite()
{
    return &this->arrow_left_s;
}

Sprite *Encyclopedia::getRightArrowSprite()
{
    return &this->arrow_right_s;
}
