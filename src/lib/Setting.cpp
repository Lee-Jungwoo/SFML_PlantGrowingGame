// #include"Setting.h"

// Setting::Setting() {
// 	this->back_t.loadFromFile("yellow_square.png");
// 	this->music_t.loadFromFile("sound_on.png");
	
// 	this->back_s = Sprite(this->back_t);
// 	this->music_s = Sprite(this->music_t);

// 	this->back_s.setPosition(135,270);
// 	this->music_s.setPosition(203,338);

// 	this->back_s.setScale(0.5, 0.5);
// 	this->music_s.setScale(0.5, 0.5);
// 	music.openFromFile("bgm.ogg");
// 	music.setLoop(true);
// 	if (this->music.getStatus() != -1)
// 		music.play();
// }


// void Setting::update()
// {
// 	printf("State: %d\n", this->music.getStatus());
// 	if(this->music.getStatus() !=0)
// 	{
// 		this->music.stop();
// 		this->music_t.loadFromFile("sound_off.png");
// 	}
// 	else
// 	{
// 		this->music.play();
// 		this->music_t.loadFromFile("sound_on.png");
// 	}
// 	this->music_s = Sprite(this->music_t);
// 	this->music_s.setPosition(203, 338);
// 	this->music_s.setScale(0.5, 0.5);
// }
// int Setting::draw(sf::RenderWindow* window)
// {
// 	window->draw(back_s);
// 	window->draw(music_s);
// 	return 0;
// }