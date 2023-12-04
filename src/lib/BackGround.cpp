#include "BackGround.h"


using namespace std;


/////////////////////////////////
BackGround::BackGround() {
	this->mode = 0;
	main_t.loadFromFile("../../0.png");
	main_s = Sprite(main_t);
	this->font.loadFromFile("../../Font-Medium.ttf");
	text.setFont(font);
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::Black);
	text.setString("DESSERT"); //thema �־����
	text.setPosition(0, 0);
	text.setStyle(sf::Text::Bold);
	
}
//void BackGround::ChangeMode(sf::Vector2i pos,GameState& gamestate)
void BackGround::ChangeMode(sf::Vector2i pos) {
	
	int x = pos.x;
	int y = pos.y;
	printf("%d %d\n", x, y);
	//0�� �ʱ�ε� ȭ��, 1�� �⺻ ���� ȭ��, 2,3,4,5�� ����Ȯ��ȭ��, 6�� ����, 7�� �̴ϰ���, 8�� ����, 9�� ����
	switch (this->mode)
	{
	case 0:
		this->mode=g_main;
		break;
	case g_main:
	{
		if (x > Slot_x1_m && y > Slot_y1_m && x < Slot_x1_M && y < Slot_y1_M) // 1
		{
			this->mode = g_slot1; slot.mode(1);
		}
		if (x > Slot_x1_m && y > Slot_y2_m && x < Slot_x1_M && y < Slot_y2_M) //2
		{
			this->mode = g_slot2; slot.mode(2);
		}
		if (x > Slot_x2_m && y > Slot_y1_m && x < Slot_x2_M && y < Slot_y1_M) // 3
		{
			this->mode = g_slot3; slot.mode(3);
		}
		if (x > Slot_x2_m && y > Slot_y2_m && x < Slot_x2_M && y < Slot_y2_M) // 4
		{
			this->mode = g_slot4; slot.mode(4);
		}
		if (x > 12 && y > 675 && x < 132 && y < 803)
			this->mode = g_shop;
		if (x > 144 && y > 675 && x < 264 && y < 803)
			this->mode = g_minigame;
		if (x > 276 && y > 675 && x < 396 && y < 803)
			this->mode = g_encyclopedia;
		if (x > 408 && y > 675 && x < 528 && y < 803)
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
			//1������
		}
		if (x > Shop_x_m && y > Shop_y2_m && x < Shop_x_M && y < Shop_y2_M)
		{
			//2������
		}
		if (x > Shop_x_m && y > Shop_y3_m && x < Shop_x_M && y < Shop_y3_M)
		{
			//3������
		}
		if (x > Shop_x_m && y > Shop_y4_m && x < Shop_x_M && y < Shop_y4_M)
		{
			//4������
		}
		if (y > 675)
		{
			this->mode = g_main;
		}
		break;
	case g_minigame:
		if (x > Shop_x_m && y > Shop_y1_m && x < Shop_x_M && y < Shop_y1_M)
		{
			//1������
		}
		if (x > Shop_x_m && y > Shop_y2_m && x < Shop_x_M && y < Shop_y2_M)
		{
			//2������
		}
		if (x > Shop_x_m && y > Shop_y3_m && x < Shop_x_M && y < Shop_y3_M)
		{
			//3������
		}
		if (x > Shop_x_m && y > Shop_y4_m && x < Shop_x_M && y < Shop_y4_M)
		{
			//4������
		}
		if (y > 675)
			this->mode = g_main;
		break;
	case g_encyclopedia:
		if (y > 675)
			this->mode = g_main;
		break;
	// case g_setting:
		// if (y > 675)
		// 	this->mode = g_main;
		// if (y< 675)
		// {
		// 	setting.update();
		// }
		
		// break;
	}
}

//int BackGround::draw(sf::RenderWindow *window, GameState& gamestate )
int BackGround::draw(sf::RenderWindow *window ) {
	
	//0�� �ʱ�ε� ȭ��, 1�� �⺻ ���� ȭ��, 2,3,4,5�� ����Ȯ��ȭ��, 6�� ����, 7�� �̴ϰ���, 8�� ����, 9�� ����
	switch (this->mode) {
	case g_loading:
	{
		if (!this->main_t.loadFromFile("../../0.png"))
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
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			//Texture gold_t;
			//Texture bucket_t;
			//Texture fertilizer_t;

			//Sprite gold_s;
			//Sprite bucket_s;
			//Sprite fertilizer_s;

			// ��ܹ�

			/* ���
			gold_t.loadFromFile("gold.png");
			gold_s = Sprite(gold_t);
			gold_s.setPosition(500,1000); ��ġ�� �����ʿ�
			*/

			// // �絿��
			// bucket.loadFromFile("assets/Buckets/WaterBucket.png");
			// bucket_s = Sprite(bucket_t);
			// bucket_s.setPosition(500,1000);
			

			/* ���
			fertilizer_t.loadFromFile("fertilizer.png");
			fertilizer_s = Sprite(fertilizer_t);
			fertilizer_s.setPosition(500,1000); ��ġ�� �����ʿ�
			*/

			//����
			main_s = Sprite(main_t);
			//�ϴܹ�
			Texture shop_t;
			Texture minigame_t;
			Texture encyclopedia_t;
			Texture setting_t;
			Sprite shop_s;
			Sprite minigame_s;
			Sprite encyclopedia_s;
			Sprite setting_s;
			shop_t.loadFromFile("../../shop.png");
			shop_s = Sprite(shop_t);
			shop_s.setPosition(12, 683);

			minigame_t.loadFromFile("../../minigame.png");
			minigame_s = Sprite(minigame_t);
			minigame_s.setPosition(144, 683);

			encyclopedia_t.loadFromFile("../../ency.png");
			encyclopedia_s = Sprite(encyclopedia_t);
			encyclopedia_s.setPosition(276, 683);

			setting_t.loadFromFile("../../setting.png");
			setting_s = Sprite(setting_t);
			setting_s.setPosition(408, 683);

			//Draw
			window->draw(main_s);
			//window -> draw(gold_s);
			window->draw(text);
			mainslot.draw(window);

			window->draw(shop_s);
			window->draw(minigame_s);
			window->draw(encyclopedia_s);
			window->draw(setting_s);
		}
		break;
	}
	case g_slot1:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			slot.draw(window);
			window->draw(text);
		}
		break;
	}
	case g_slot2:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			slot.draw(window);
			window->draw(text);
		}
		break;
	}
	case g_slot3:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			slot.draw(window);
			window->draw(text);
		}
		break;
	}
	case g_slot4:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			slot.draw(window);
			window->draw(text);
		}
		break;
	}
	case g_shop:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			window->draw(text);
			shop.draw(window);
		}
		break;
	}
	case g_minigame:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			window->draw(main_s);
			window->draw(text);
			minigame.draw(window);
		}
		break;
	}
	case g_encyclopedia:
	{
		if (!this->main_t.loadFromFile("../../Dessert.png"))
		{
			return EXIT_FAILURE;
		}
		else
		{
			Encyclopedia encyclopedia;
			window->draw(main_s);
			window->draw(text);
			encyclopedia.draw(window);
		}
		break;
	}
	// case g_setting:
	
	// {
	// 	if (!this->main_t.loadFromFile("../../Dessert.png"))
	// 	{
	// 		return EXIT_FAILURE;
	// 	}
	// 	else
	// 	{
	// 		window->draw(main_s);
	// 		window->draw(text);
	// 		setting.draw(window);
	// 	}

	// }
	}

	return 99; //good return
}

