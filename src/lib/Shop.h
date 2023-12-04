#ifndef SHOP_H
#define SHOP_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Shop {
private:
	Texture slot1_t;
	Texture slot2_t;
	Texture slot3_t;
	Texture slot4_t;
	Texture back1_t;
	Texture back2_t;
	Texture back3_t;
	Texture back4_t;
	Sprite slot1_s;
	Sprite slot2_s;
	Sprite slot3_s;
	Sprite slot4_s;
	Sprite back1_s;
	Sprite back2_s;
	Sprite back3_s;
	Sprite back4_s;

	Text text1;
	Text text2;
	Text text3;
	Text text4;

	Font font;
public:
	Shop();
	~Shop() {}
	int draw(sf::RenderWindow* window);
};
#endif // !SHOP_H

