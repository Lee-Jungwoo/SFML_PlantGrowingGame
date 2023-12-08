#include "Setting.h"

Setting::Setting()
{
	this->back_t.loadFromFile("../../yellow_square.png");
	this->music_t.loadFromFile("../../sound_on.png");

	this->back_s = Sprite(this->back_t);
	this->music_s = Sprite(this->music_t);

	this->back_s.setPosition(135, 270);
	this->music_s.setPosition(175, 326);

	this->back_s.setScale(0.5, 0.5);
	// this->music_s.setScale(0.5, 0.5);

	music_Desert.openFromFile("../../bgm.ogg");
	music_Desert.setLoop(true);

	music_Temperate.openFromFile("../../bgm3.ogg");
	music_Temperate.setLoop(true);
	

	music_Tropical.openFromFile("../../bgm2.ogg");
	music_Tropical.setLoop(true);
	

	currentStage = Stage::Desert;

	currentMusic = &music_Desert;
	currentMusic->play();
}

void Setting::update()
{
	printf("State: %d\n", this->currentMusic->getStatus());
	if (this->currentMusic->getStatus() != SoundSource::Status::Stopped)
	{
		this->currentMusic->stop();
		this->music_t.loadFromFile("../../sound_off.png");
	}
	else
	{
		this->currentMusic->play();
		this->music_t.loadFromFile("../../sound_on.png");
	}
}
void Setting::setSongByStage(Stage stage)
{
	if (this->currentStage == stage)
		return;

	else
	{
		this->currentStage = stage;
		currentMusic->stop();
		switch (stage)
		{
		case Stage::Desert:

			currentMusic = &music_Desert;
			break;
		case Stage::Temperate:
			currentMusic = &music_Temperate;
			break;

		case Stage::Tropical:
			currentMusic = &music_Tropical;
			break;
		
		default:
			break;
		}

		currentMusic->play();
		
	}
}
int Setting::draw(sf::RenderWindow *window)
{
	// window->draw(back_s);
	window->draw(music_s);
	return 0;
}