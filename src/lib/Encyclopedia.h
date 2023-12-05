#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H
#include "State.h"
#include "Resource.h"
using namespace sf;

class Encyclopedia {
private:
	// Texture back1_t;
	// Texture back2_t;
	// Texture back3_t;
	// Texture back4_t;
	Texture back_t;

	// Sprite back1_s;
	// Sprite back2_s;
	// Sprite back3_s;
	// Sprite back4_s;
	Sprite back_s[4];

	// Texture slot1_t;
	// Texture slot2_t;
	// Texture slot3_t;
	// Texture slot4_t;
	Texture slot_t[4];


	// Sprite slot1_s;
	// Sprite slot2_s;
	// Sprite slot3_s;
	// Sprite slot4_s;
	Sprite slot_s[4];

	Text text1;
	Text text2;
	Text text3;
	Text text4;

	Font font;
	int currentNumOfPlantsInDict;
	std::vector<PlantSpecies> plantsInCurrentStage;
	Stage stage;
	
public:
	Encyclopedia(GameState &state);
	~Encyclopedia(){}
	int draw(sf::RenderWindow* window);
	int getCurrentNumOfPlantsInDict(){return currentNumOfPlantsInDict;}
	std::vector<PlantSpecies> getPlantsInCurrentStage();
	Sprite * getDictSlotSprite(int num){return &back_s[num];} //0~3

};
#endif // !ENCYCLOPEDIA_H

