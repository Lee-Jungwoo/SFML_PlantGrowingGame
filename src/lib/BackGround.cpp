#include "BackGround.h"

using namespace std;

/////////////////////////////////
BackGround::BackGround(GameState &state, sf::RenderWindow *window)
{
	this->mode = 0;
	this->window = window;

	// Background screen
	main_t.loadFromFile("../../assets/LoadingScreen.png");
	main_s = Sprite(main_t);

	// Next Day Button
	nextDay_t.loadFromFile("../../next_day.png");
	nextDay_s = Sprite(nextDay_t);
	nextDay_s.setPosition(443, 143);

	// Current Stage init.
	this->font.loadFromFile("../../assets/Fonts/Font-Medium.ttf");
	stage.setFont(font);
	stage.setCharacterSize(45);
	stage.setFillColor(sf::Color::Black);
	stage.setString("DESERT");
	stage.setPosition(0, 0);
	stage.setStyle(sf::Text::Bold);

	mainslot = new MainSlot(state);
	shop = new Shop(state);
	encyclopedia = new Encyclopedia(state, Stage::Desert);

	back_t.loadFromFile("../../back.png");
	back_s.setTexture(back_t);
	back_s.setPosition(0, 765);
	dictIdx = 0;
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
		if (state.isAllHandled() && nextDay_s.getGlobalBounds().contains(x, y))
		{
			state.nextDay();
			
		}


		if (shop_s.getGlobalBounds().contains(x, y))
			this->mode = g_shop;
		if (minigame_s.getGlobalBounds().contains(x, y))
			this->mode = g_minigame;
		if (encyclopedia_s.getGlobalBounds().contains(x, y))
			this->mode = g_encyclopedia;
		if (setting_s.getGlobalBounds().contains(x, y))
			this->mode = g_setting;


		if(state.getCurrentStage() == Stage::End){
			this->mode = g_clear;
		}
		break;
	}
	case g_slot1:
	case g_slot2:
	case g_slot3:
	case g_slot4:
	{
		int plantSlotIdx = this->mode - 2;
		// int plantSlotNum = this->mode - 1;

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
				this->mode = g_main;
			}
			else if (slot.getFertButtonSprite()->getGlobalBounds().contains(x, y))
			{
				std::cout << "Fertilizing" << std::endl;
				plantSlot->getPlant()->fillEnergy(*state.getFertBucket());
				this->mode = g_main;
			}
			else if (slot.getSkipButtonSprite()->getGlobalBounds().contains(x, y))
			{
				std::cout << "Skipping" << std::endl;
				plantSlot->getPlant()->skipThisTime();
				this->mode = g_main;
			}
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			std::cout << "Going back to main" << std::endl;
			this->mode = g_main;
		}

		break;
	}
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
	{
		for (int i = 1; i <= MINIGAME_NUM; i++)
		{
			if (minigame.getSlotSprite(i)->getGlobalBounds().contains(x, y))
			{
				if (minigame.startGame(i, window, state))
				{
					state.getWaterBucket()->fill();
					state.getFertBucket()->fill();
				}
				this->mode = g_main;
			}
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		break;
	}
	case g_encyclopedia:
	{
		for (int i = 0; i < encyclopedia->getCurrentNumOfPlantsInDict(); i++)
		{
			if (encyclopedia->getDictSlotSprite(i)->getGlobalBounds().contains(x, y))
			{
				this->mode = g_encyclopedia_info;
				encyInfoView.changeMode(encyclopedia->getPlantsInCurrentStage()[i]);
			}
		}

		if (encyclopedia->getLeftArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Left arrow clicked." << std::endl;

			encyclopedia->prevStage();
		}
		else if (encyclopedia->getRightArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Right Arrow clicked" << std::endl;

			encyclopedia->nextStage();
		}

		if (back_s.getGlobalBounds().contains(x, y))
		{
			this->mode = g_main;
		}
		break;
	}
	case g_encyclopedia_info:
	{
		// std::cout << "PLATNS CURRENTLY IN THE ENCYCLOPEDIA  ARE:\n";
		// for (std::vector<PlantSpecies>::iterator iter = encyclopedia->getPlantsInCurrentStage().begin(); iter != encyclopedia->getPlantsInCurrentStage().end(); iter++)
		// {
		// 	std::cout << Resource::getName(*iter) << std::endl;
		// }

		std::vector<PlantSpecies> plantInCurrentStageDict = encyclopedia->getPlantsInCurrentStage();

		if (encyInfoView.getLeftArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Left arrow clicked" << std::endl;
			if (dictIdx != 0)
				encyInfoView.changeMode(plantInCurrentStageDict[--dictIdx]);
			else
				encyInfoView.changeMode(plantInCurrentStageDict[plantInCurrentStageDict.size() - 1]);
		}
		else if (encyInfoView.getRightArrowSprite()->getGlobalBounds().contains(x, y))
		{
			std::cout << "Right Arrow clicked" << std::endl;
			if (dictIdx != plantInCurrentStageDict.size() - 1)
				encyInfoView.changeMode(plantInCurrentStageDict[++dictIdx]);
			else
				encyInfoView.changeMode(plantInCurrentStageDict[0]);
		}
		if (back_s.getGlobalBounds().contains(x, y))
		{
			std::cout << "Going back to main" << std::endl;
			this->mode = g_main;
		}
		break;
	}
	case g_setting:
	{
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
	case g_clear:
	{
		window->close();
		return;
	}
	}
}

int BackGround::draw(GameState &state)
{
	stage.setString(Resource::getStageName(state.getCurrentStage()));
	switch (state.getCurrentStage())
	{
	case Stage::Desert:
		if (!this->main_t.loadFromFile("../../assets/Desert/Desert_background.png"))
		{
			return EXIT_FAILURE;
		}
		setting.setSongByStage(state.getCurrentStage());
		break;
	case Stage::Temperate:
		if (!this->main_t.loadFromFile("../../assets/Temperate/Temperate_background.png"))
		{
			return EXIT_FAILURE;
		}
		setting.setSongByStage(state.getCurrentStage());
		break;
	case Stage::Tropical:
		if (!this->main_t.loadFromFile("../../assets/Tropical/Tropical_background.png"))
		{
			return EXIT_FAILURE;
		}
		setting.setSongByStage(state.getCurrentStage());
		break;

	case Stage::End:
		if(!this->main_t.loadFromFile("../../assets/GameClear.png"))
			{
			return 0;
			}
		setting.setSongByStage(state.getCurrentStage());
		break;
	default:
		std::cout << "ERROR while fetching current stage: \n in Function Backgroung::draw()" << std::endl;
		break;
	}

	switch (this->mode)
	{
	case g_loading:
	{
		if (!this->main_t.loadFromFile("../../assets/LoadingScreen.png"))
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

		Text day; // day
		day.setFont(font);
		day.setCharacterSize(35);
		day.setFillColor(sf::Color::Black);
		day.setPosition(0, 80);
		day.setString("Day: " + to_string(state.getCurrentDay()));

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
		window->draw(day);
		window->draw(*w);
		window->draw(wt);
		window->draw(*f);
		window->draw(ft);

		// Draw "Main screen"
		mainslot->draw(window, state);
		if (state.isAllHandled() && state.getSlotNum() != 0)
		{
			window->draw(nextDay_s);
		}

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
		Stage s = encyclopedia->getStage();
		std::cout << "Current Stage of dict =>" << Resource::getStageName(s) << std::endl;

		Text stage_of_dict; // stage_of_dict
		stage_of_dict.setFont(font);
		stage_of_dict.setCharacterSize(40);
		stage_of_dict.setFillColor(sf::Color::Black);
		stage_of_dict.setPosition(0, 0);
		stage_of_dict.setString(Resource::getStageName(s));

		delete encyclopedia;
		encyclopedia = new Encyclopedia(state, s);
		window->draw(main_s);
		window->draw(stage_of_dict);
		window->draw(back_s);
		encyclopedia->draw(window);

		break;
	}
	case g_encyclopedia_info:
	{
		window->draw(main_s);

		window->draw(back_s);
		encyInfoView.draw(window);
		break;
	}

	case g_setting:
	{
		this->drawScaffold(window);
		setting.draw(window);
		break;
	}

	case g_clear:
		window->draw(main_s);
		break;
	}

	return 99; // good return
}

void BackGround::drawScaffold(sf::RenderWindow *window)
{
	window->draw(main_s);

	window->draw(back_s);
}
