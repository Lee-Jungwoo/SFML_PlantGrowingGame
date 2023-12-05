#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Minigame.h"
#include "Shop.h"
#include "Encyclopedia.h"
#include "Setting.h"
#include "MainSlot.h"
#include "Slot.h"
#include "Buckets.h"

/////////background Mode//////////
#define g_loading 0
#define g_main 1
#define g_slot1 2
#define g_slot2 3
#define g_slot3 4
#define g_slot4 5
#define g_shop 6
#define g_minigame 7
#define g_encyclopedia 8
#define g_setting 9
/////////////////////////////////
// #define Slot_x1_m 75
// #define Slot_x1_M 225
// #define Slot_x2_m 315
// #define Slot_x2_M 465
// #define Slot_y1_m 263
// #define Slot_y1_M 413
// #define Slot_y2_m 488
// #define Slot_y2_M 638
/////////////////////////////////
#define Arrow_l_x_m 23
#define Arrow_l_x_M 135
#define Arrow_r_x_m 405
#define Arrow_r_x_M 518
#define Arrow_y_m 345
#define Arrow_y_M 458
/////////////////////////////////
#define Shop_x_m 8
#define Shop_x_M 533
#define Shop_y1_m 144
#define Shop_y1_M 188
#define Shop_y2_m 275
#define Shop_y2_M 320
#define Shop_y3_m 406
#define Shop_y3_M 451
#define Shop_y4_m 539
#define Shop_y4_M 584
/////////////////////////////////

class BackGround
{
private:
	Shop *shop;
	Minigame minigame;
	MainSlot * mainslot;
	Slot slot;
	Bucket bucket;
	Setting setting;
	int mode; // Current screen view.
	sf::Texture main_t;
	sf::Sprite main_s;
	sf::Text stage;
	sf::Text gold;
	sf::Font font;

	//Bottom bar textures & sprites.
	sf::Texture shop_t;
	sf::Texture minigame_t;
	sf::Texture encyclopedia_t;
	sf::Texture setting_t;
	sf::Sprite shop_s;
	sf::Sprite minigame_s;
	sf::Sprite encyclopedia_s;
	sf::Sprite setting_s;

	//Bottom bar (go back) texture & sprite;
	sf::Texture back_t;
	sf::Sprite back_s;
	

public:
	BackGround(GameState &);
	~BackGround() {}
	void ChangeMode(sf::Vector2i pos, GameState &);
	virtual int draw(sf::RenderWindow *window, GameState &);
};
#endif // !BACKGROUND_H
