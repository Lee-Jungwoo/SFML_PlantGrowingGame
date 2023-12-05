#include "Encyclopedia.h"
#include <algorithm>
Encyclopedia::Encyclopedia(GameState &state) {

	// text1.setFont(font);
	// text1.setCharacterSize(25);
	// text1.setFillColor(sf::Color::Black);
	// text1.setString("Information1");
	// text1.setPosition(360, 196);
	// text1.setStyle(sf::Text::Bold);

	// text2.setFont(font);
	// text2.setCharacterSize(25);
	// text2.setFillColor(sf::Color::Black);
	// text2.setString("Information2");
	// text2.setPosition(360, 372);
	// text2.setStyle(sf::Text::Bold);

	// text3.setFont(font);
	// text3.setCharacterSize(25);
	// text3.setFillColor(sf::Color::Black);
	// text3.setString("Information3");
	// text3.setPosition(360, 548);
	// text3.setStyle(sf::Text::Bold);

	// text4.setFont(font);
	// text4.setCharacterSize(25);
	// text4.setFillColor(sf::Color::Black);
	// text4.setString("Information4");
	// text4.setPosition(360, 724);
	// text4.setStyle(sf::Text::Bold);

	
	currentNumOfPlantsInDict = state.getPlantBook()->size();

	/*
	TESTING
	*/
	// currentNumOfPlantsInDict = 4;
	stage = Stage::Desert;

	plantsInCurrentStage = *(state.getPlantBook());
	plantsInCurrentStage.erase(std::remove_if(plantsInCurrentStage.begin(),plantsInCurrentStage.end(),[&](const PlantSpecies &species) {
        return Resource::getStageByPlant(species) != "Desert";}),plantsInCurrentStage.end());

	//DEBUGGING
	std::cout<<"PLATNS CURRENTLY IN THE ENCYCLOPEDIA  ARE:\n";
	for(std::vector<PlantSpecies>::iterator iter = plantsInCurrentStage.begin(); iter != plantsInCurrentStage.end() ;iter++){
		std::cout<<Resource::getName(*iter)<<std::endl;
	}
	//DEBUGGING

	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		slot_t[i] = *Resource::getTexture(plantsInCurrentStage[i], 4);
	}

	this->back_t.loadFromFile("../../yellow_rect.png");


	for (int i = 0; i < currentNumOfPlantsInDict; i++)
	{
		slot_s[i] = Sprite(this->slot_t[i]); // Plant sprite init.
		slot_s[i].setScale(0.35f,0.35f); //to make the sprite 70 x 70 size.
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

int Encyclopedia::draw(sf::RenderWindow* window)
{
	for(int i=0;i<currentNumOfPlantsInDict;i++){
		window->draw(this->back_s[i]);
	}

	for(int i=0;i<currentNumOfPlantsInDict;i++){
		window->draw(this->slot_s[i]);
	}

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
