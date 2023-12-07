#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H
#include "State.h"
#include "Resource.h"
using namespace sf;

class Encyclopedia
{
private:
	Texture back_t;

	Sprite back_s[4];

	Texture slot_t[4];

	Texture arrow_left_t;
	Sprite arrow_left_s;

	Texture arrow_right_t;
	Sprite arrow_right_s;

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
	Encyclopedia(GameState &state, Stage stage);
	~Encyclopedia() {}

	int draw(sf::RenderWindow *window);

	int getCurrentNumOfPlantsInDict() { return currentNumOfPlantsInDict; }
	std::vector<PlantSpecies> getPlantsInCurrentStage();

	bool nextStage();
	bool prevStage();
	Stage getStage() { return stage; }
	

	Sprite *getLeftArrowSprite();
	Sprite *getRightArrowSprite();
	Sprite *getDictSlotSprite(int num) { return &back_s[num]; } // 0~3
};
#endif // !ENCYCLOPEDIA_H
