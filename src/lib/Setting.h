#ifndef SETTING_H
#define SETTING_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Resource.h"

using namespace sf;
class Setting {
private:
	Texture back_t;
	Texture music_t;

	Sprite back_s;
	Sprite music_s;

	Music music_Desert;
	Music music_Temperate;
	Music music_Tropical;

	Music * currentMusic;

	Stage currentStage;
public:
	Setting();
	~Setting() {}
	int draw(sf::RenderWindow* window);
	void update();
	void setSongByStage(Stage stage);
};

#endif // !SETTING_H

