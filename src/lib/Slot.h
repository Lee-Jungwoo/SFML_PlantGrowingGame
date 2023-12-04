#ifndef SLOT_H
#define SLOT_H
#include <SFML/Graphics.hpp>



using namespace sf;
class Slot
{
private:
	Texture slot_t;
	Sprite slot_s;

	Texture arrow_left_t;
	Sprite arrow_left_s;

	Texture arrow_right_t;
	Sprite arrow_right_s;

	Text text;
	Font font;
public:
	Slot();
	~Slot() {}
	int draw(sf::RenderWindow*);
	void mode(int);
};
#endif // !SLOT_H
