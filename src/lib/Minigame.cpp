#include "Minigame.h"

Minigame::Minigame()
{
	this->back1_t.loadFromFile("../../yellow_rect.png");
	this->back2_t.loadFromFile("../../yellow_rect.png");
	this->back3_t.loadFromFile("../../yellow_rect.png");
	this->back4_t.loadFromFile("../../yellow_rect.png");

	this->back1_s = Sprite(this->back1_t);
	this->back2_s = Sprite(this->back2_t);
	this->back3_s = Sprite(this->back3_t);
	this->back4_s = Sprite(this->back4_t);

	back1_s.setPosition(41, 230);
	back2_s.setPosition(41, 350);
	back3_s.setPosition(41, 470);
	back4_s.setPosition(41, 590);
}

Sprite *Minigame::getSlotSprite(int num)
{
	switch (num)
	{
	case 1:
		return &back1_s;

	case 2:
		return &back2_s;

	case 3:
		return &back3_s;
	case 4:
		return &back4_s;
	default:
		std::cout << "ERROR while fetchig slot sprites in minigame: invalid argument" << std::endl;
		return nullptr;
	}
}

int Minigame::draw(sf::RenderWindow *window)
{

	window->draw(back1_s);
	window->draw(back2_s);
	window->draw(back3_s);

	return 0;
}

bool Minigame::startGame(int num, sf::RenderWindow *window)
{
	switch (num)
	{
	case 1:
		std::cout << "game 1 going" << std::endl;
		if (Game::startGame(window))
		{
			std::cout << "kk" << std::endl;
			return true; 
		}
		else
		{
			std::cout << "GAME FAILED" << std::endl;
			return false;
		}
		break;
	case 2:
		std::cout << "game 2 going" << std::endl;
		if (AvoidPoop::startGame(window))
		{
			std::cout << "kk" << std::endl;
			return true; 
		}
		else
		{
			std::cout << "GAME FAILED" << std::endl;
			return false;
		}
		break;
	case 3:
		std::cout << "game 3 going" << std::endl;
		if (Game2::startGame(window))
		{
			std::cout << "kk" << std::endl;
			return true; 
		}
		else
		{
			std::cout << "GAME FAILED" << std::endl;
			return false;
		}
		break;
	default:
		break;
	}
	return false;
}
