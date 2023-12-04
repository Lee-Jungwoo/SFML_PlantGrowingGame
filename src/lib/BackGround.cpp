#include "BackGround.h"

using namespace std;

/////////////////////////////////
BackGround::BackGround()
{
	this->mode = 0;

	main_t.loadFromFile("../../LoadingScreen.png");
	main_s = Sprite(main_t);

	this->font.loadFromFile("../../Font-Medium.ttf");
	stage.setFont(font);
	stage.setCharacterSize(45);
	stage.setFillColor(sf::Color::Black);
	stage.setString("DESERT");
	stage.setPosition(0, 0);
	stage.setStyle(sf::Text::Bold);
}
void BackGround::ChangeMode(sf::Vector2i pos, GameState &state)
{

	int x = pos.x;
	int y = pos.y;

	switch (this->mode)
	{
	case g_loading:
		this->mode = g_main;
		break;
	case g_main:
	{ /*
		 if (this->mainslot.getSprite(1)->getGlobalBounds().contains(x, y)) // 1
		 {
			 this->mode = g_slot1;
			 slot.mode(1);
		 }
		 if (x > Slot_x1_m && y > Slot_y2_m && x < Slot_x1_M && y < Slot_y2_M) // 2
		 {
			 this->mode = g_slot2;
			 slot.mode(2);
		 }
		 if (x > Slot_x2_m && y > Slot_y1_m && x < Slot_x2_M && y < Slot_y1_M) // 3
		 {
			 this->mode = g_slot3;
			 slot.mode(3);
		 }
		 if (x > Slot_x2_m && y > Slot_y2_m && x < Slot_x2_M && y < Slot_y2_M) // 4
		 {
			 this->mode = g_slot4;
			 slot.mode(4);
		 }
 */
		for (int i = 1; i <= 4; i++)
		{
			if (this->mainslot.getSprite(i)->getGlobalBounds().contains(x, y)) // 1
			{
				this->mode = g_slot1 + (i - 1);
				slot.mode(i);
			}
		}

		if (shop_s.getGlobalBounds().contains(x,y))
			this->mode = g_shop;
		if (minigame_s.getGlobalBounds().contains(x,y))
			this->mode = g_minigame;
		if (encyclopedia_s.getGlobalBounds().contains(x,y))
			this->mode = g_encyclopedia;
		if (setting_s.getGlobalBounds().contains(x,y))
			this->mode = g_setting;
		break;
	}
	case g_slot1:
		if (x > Arrow_l_x_m && y > Arrow_y_m && x < Arrow_l_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot4;
			slot.mode(4);
		}
		if (x > Arrow_r_x_m && y > Arrow_y_m && x < Arrow_r_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot2;
			slot.mode(2);
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_slot2:
		if (x > Arrow_l_x_m && y > Arrow_y_m && x < Arrow_l_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot1;
			slot.mode(1);
		}
		if (x > Arrow_r_x_m && y > Arrow_y_m && x < Arrow_r_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot3;
			slot.mode(3);
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_slot3:
		if (x > Arrow_l_x_m && y > Arrow_y_m && x < Arrow_l_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot2;
			slot.mode(2);
		}
		if (x > Arrow_r_x_m && y > Arrow_y_m && x < Arrow_r_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot4;
			slot.mode(4);
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_slot4:
		if (x > Arrow_l_x_m && y > Arrow_y_m && x < Arrow_l_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot3;
			slot.mode(3);
		}
		if (x > Arrow_r_x_m && y > Arrow_y_m && x < Arrow_r_x_M && y < Arrow_y_M)
		{
			this->mode = g_slot1;
			slot.mode(1);
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_shop:
		if (x > Shop_x_m && y > Shop_y1_m && x < Shop_x_M && y < Shop_y1_M)
		{
			// 1������
		}
		if (x > Shop_x_m && y > Shop_y2_m && x < Shop_x_M && y < Shop_y2_M)
		{
			// 2������
		}
		if (x > Shop_x_m && y > Shop_y3_m && x < Shop_x_M && y < Shop_y3_M)
		{
			// 3������
		}
		if (x > Shop_x_m && y > Shop_y4_m && x < Shop_x_M && y < Shop_y4_M)
		{
			// 4������
		}
		if (y > 675)
		{
			this->mode = g_main;
		}
		break;
	case g_minigame:
		if (x > Shop_x_m && y > Shop_y1_m && x < Shop_x_M && y < Shop_y1_M)
		{
			// 1������
		}
		if (x > Shop_x_m && y > Shop_y2_m && x < Shop_x_M && y < Shop_y2_M)
		{
			// 2������
		}
		if (x > Shop_x_m && y > Shop_y3_m && x < Shop_x_M && y < Shop_y3_M)
		{
			// 3������
		}
		if (x > Shop_x_m && y > Shop_y4_m && x < Shop_x_M && y < Shop_y4_M)
		{
			// 4������
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_encyclopedia:
		if (y > 675)
			this->mode = g_main;
		break;
	case g_setting:
		if (y > 675)
			this->mode = g_main;
		if (y < 675)
		{
			setting.update();
		}

		break;
	}
}

int BackGround::draw(sf::RenderWindow *window, GameState &state)
{

	switch (state.getCurrentStage())
	{
	case Stage::Desert:
		if (!this->main_t.loadFromFile("../../assets/Desert/Desert_background.png"))
		{
			return EXIT_FAILURE;
		}
		break;
	case Stage::Temperate:
		if (!this->main_t.loadFromFile("../../assets/Temperate/Temperate_background.png"))
		{
			return EXIT_FAILURE;
		}
		break;
	case Stage::Tropical:
		if (!this->main_t.loadFromFile("../../assets/Tropical/Tropical_background.png"))
		{
			return EXIT_FAILURE;
		}
		break;
	default:
		std::cout << "ERROR while fetching current stage: \n in Function Backgroung::draw()" << std::endl;
		break;
	}

	switch (this->mode)
	{
	case g_loading:
	{
		if (!this->main_t.loadFromFile("../../LoadingScreen.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
		}
		break;
	}
	case g_main:
	{

		Sprite *w; // waterBucket
		Text wt;

		Sprite *f; // fertBucket
		Text ft;

		gold.setFont(font);
		gold.setCharacterSize(30);
		gold.setFillColor(sf::Color::Black);
		gold.setString("Gold: " + to_string(state.getGold()));

		gold.setPosition(0, 50);
		gold.setStyle(sf::Text::Bold);

		// make waterbucket
		w = state.getWaterBucketSprite();
		w->setPosition(300, 0);
		w->setScale(0.4f, 0.4f);

		////waterBucket's text.
		wt.setFont(font);
		wt.setCharacterSize(15);
		wt.setFillColor(sf::Color::Black);
		wt.setString(to_string(state.getWater()));

		wt.setPosition(330, 80);
		wt.setStyle(sf::Text::Bold);

		// make fertBucket
		f = state.getFertBucketSprite();
		f->setPosition(400, 0);
		f->setScale(0.4f, 0.4f);

		////fertBucket's text.
		ft.setFont(font);
		ft.setCharacterSize(15);
		ft.setFillColor(sf::Color::Black);
		ft.setString(to_string(state.getFert()));

		ft.setPosition(425, 80);
		ft.setStyle(sf::Text::Bold);

		// main Background
		main_s = Sprite(main_t);

		// Misc. textures and sprites
		shop_t.loadFromFile("../../shop.png");
		shop_s = Sprite(shop_t);
		shop_s.setPosition(0, 765);

		minigame_t.loadFromFile("../../minigame.png");
		minigame_s = Sprite(minigame_t);
		minigame_s.setPosition(135, 765);

		encyclopedia_t.loadFromFile("../../ency.png");
		encyclopedia_s = Sprite(encyclopedia_t);
		encyclopedia_s.setPosition(270, 765);

		setting_t.loadFromFile("../../setting.png");
		setting_s = Sprite(setting_t);
		setting_s.setPosition(405, 765);

		// Draw "Top bar"
		window->draw(main_s);
		window->draw(gold);
		window->draw(stage);
		window->draw(*w);
		window->draw(wt);
		window->draw(*f);
		window->draw(ft);

		// Draw "Main screen"
		mainslot.draw(window);

		// Draw "Bottom bar"
		window->draw(shop_s);
		window->draw(minigame_s);
		window->draw(encyclopedia_s);
		window->draw(setting_s);

		break;
	}
	case g_slot1:
	{

		window->draw(main_s);
		slot.draw(window);
		window->draw(stage);

		break;
	}
	case g_slot2:
	{

		window->draw(main_s);
		slot.draw(window);
		window->draw(stage);

		break;
	}
	case g_slot3:
	{

		window->draw(main_s);
		slot.draw(window);
		window->draw(stage);

		break;
	}
	case g_slot4:
	{

		window->draw(main_s);
		slot.draw(window);
		window->draw(stage);

		break;
	}
	case g_shop:
	{

		window->draw(main_s);
		window->draw(stage);
		shop.draw(window);

		break;
	}
	case g_minigame:
	{

		window->draw(main_s);
		window->draw(stage);
		minigame.draw(window);

		break;
	}
	case g_encyclopedia:
	{

		Encyclopedia encyclopedia;
		window->draw(main_s);
		window->draw(stage);
		encyclopedia.draw(window);

		break;
	}
	case g_setting:

	{

		window->draw(main_s);
		window->draw(stage);
		setting.draw(window);
	}
	}

	return 99; // good return
}
