#include "BackGround.h"

using namespace std;

/////////////////////////////////
BackGround::BackGround(GameState &state, sf::RenderWindow *window)
{
	this->mode = 0;
	this->window = window;

	main_t.loadFromFile("../../LoadingScreen.png");
	main_s = Sprite(main_t);

	this->font.loadFromFile("../../Font-Medium.ttf");
	stage.setFont(font);
	stage.setCharacterSize(45);
	stage.setFillColor(sf::Color::Black);
	stage.setString("DESERT");
	stage.setPosition(0, 0);
	stage.setStyle(sf::Text::Bold);

	mainslot = new MainSlot(state);
	shop = new Shop(state);

	back_t.loadFromFile("../../back.png");
	back_s.setTexture(back_t);
	back_s.setPosition(0, 765);
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
	{
		for (int i = 1; i <= 4; i++)
		{
			if (this->mainslot->getSprite(i)->getGlobalBounds().contains(x, y)) // 1
			{
				this->mode = g_slot1 + (i - 1);
				slot.mode(i, state);
			}
		}

		if (shop_s.getGlobalBounds().contains(x, y))
			this->mode = g_shop;
		if (minigame_s.getGlobalBounds().contains(x, y))
			this->mode = g_minigame;
		if (encyclopedia_s.getGlobalBounds().contains(x, y))
			this->mode = g_encyclopedia;
		if (setting_s.getGlobalBounds().contains(x, y))
			this->mode = g_setting;
		break;
	}
	case g_slot1:
	case g_slot2:
	case g_slot3:
	case g_slot4:
	{
		int plantSlotIdx = this->mode - 2;
		int plantSlotNum = this->mode - 1;
		PlantSlot *plantSlot = state.getPlantSlot(plantSlotIdx);

		if (slot.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Left arrow clicked" << std::endl;
			if (this->mode == g_slot1)
			{
				this->mode = g_slot4;
			}
			else
			{
				this->mode -= 1;
			}

			slot.mode(this->mode - 1, state);
		}
		else if (slot.getRightArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Right Arrow clicked" << std::endl;
			if (this->mode == g_slot4)
			{
				this->mode = g_slot1;
			}
			else
			{
				this->mode += 1;
			}

			slot.mode(this->mode - 1, state);
		}
		else if (!plantSlot->isEmpty())
		{

			if (slot.getWaterButtonSprite()->getGlobalBounds().contains(x, y))
			{
				std::cout << "Watering" << std::endl;
				plantSlot->getPlant()->fillWater(*state.getWaterBucket());
			}
			else if (slot.getFertButtonSprite()->getGlobalBounds().contains(x, y))
			{
				std::cout << "Fertilizing" << std::endl;
				plantSlot->getPlant()->fillEnergy(*state.getFertBucket());
			}
			else if (slot.getSkipButtonSprite()->getGlobalBounds().contains(x, y))
			{
				std::cout << "Skipping" << std::endl;
				plantSlot->getPlant()->skipThisTime();
			}
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			std::cout << "Going back to main" << std::endl;
			this->mode = g_main;
		}

		break;
	}

		/*
		if (slot.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot4;

					slot.mode(4, state);
				}
				else if (slot.getRightArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot2;
					slot.mode(2, state);
				}
				else if (y >= 765)
					this->mode = g_main;
				break;
			}
			case g_slot2:
			{
				if (slot.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot1;
					slot.mode(1, state);
				}
				else if (slot.getRightArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot3;
					slot.mode(3, state);
				}
				else if (y > 675)
					this->mode = g_main;
				break;
			}
			case g_slot3:
			{
				if (slot.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot2;
					slot.mode(2, state);
				}
				else if (slot.getRightArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot4;
					slot.mode(4, state);
				}
				else if (y > 675)
					this->mode = g_main;
				break;
			}
			case g_slot4:
			{
				if (slot.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot3;
					slot.mode(3, state);
				}
				else if (slot.getRightArrowSprite()->getGlobalBounds().contains(x, y))
				{
					this->mode = g_slot1;
					slot.mode(1, state);
				}
				else if (y > 675)
					this->mode = g_main;
				break;
			}
			*/
	case g_shop:
	{
		for (int i = 1; i <= state.getRemainingPlantsInShop()->size(); i++)
		{
			const FloatRect &f = shop->getSlotSprite(i)->getGlobalBounds();

			if (f.contains(x, y))
			{
				state.buyNewPlant(i);
			}
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		break;
	}
	case g_minigame:
		for (int i = 1; i <= MINIGAME_NUM; i++)
		{
			if (minigame.getSlotSprite(i)->getGlobalBounds().contains(x, y))
			{
				minigame.startGame(i, window);
			}
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		break;
	case g_encyclopedia:
		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		break;
	case g_setting:
		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		if (y < 675)
		{
			setting.update();
		}

		break;
	}
}

int BackGround::draw(GameState &state)
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
		delete mainslot;
		mainslot = new MainSlot(state);

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
		mainslot->draw(window, state);

		// Draw "Bottom bar"
		window->draw(shop_s);
		window->draw(minigame_s);
		window->draw(encyclopedia_s);
		window->draw(setting_s);

		break;
	}
	case g_slot1:
	case g_slot2:
	case g_slot3:
	case g_slot4:
	{

        this->drawScaffold(window);
        slot.draw(window);

		break;
	}
	case g_shop:
	{

		delete shop;
		shop = new Shop(state);

		this->drawScaffold(window);
		shop->draw(window, state);

		break;
	}
	case g_minigame:
	{

		this->drawScaffold(window);
		minigame.draw(window);

		break;
	}
	case g_encyclopedia:
	{

		Encyclopedia encyclopedia;
		this->drawScaffold(window);
		encyclopedia.draw(window);

		break;
	}
	case g_setting:
	{
		this->drawScaffold(window);
		setting.draw(window);
	}
	}

	return 99; // good return
}

void BackGround::drawScaffold(sf::RenderWindow *window)
{
    window->draw(main_s);
    window->draw(stage);
    window->draw(back_s);
}
