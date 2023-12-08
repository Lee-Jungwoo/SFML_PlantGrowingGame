#include "mini_game_HM_2.h"

void Game2::initializeVariables()
{
	this->window = nullptr;

	// Game2 logics
	this->endGame = false;
	this->points = 0;
	this->health = 10;
	this->enemySpawnTimerMax = 5.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 1;
	this->mouseHeld = false;
	this->enemyspeed = 0;
	this->clock.restart();
}

void Game2::initWindow(sf::RenderWindow * window)
{
	this->window = window;
}

void Game2::initFonts()
{
	if (!this->font.loadFromFile("../../assets/Fonts/Font-Medium.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load from file";
	}
}

void Game2::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(50);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("None");
	this->uiText.setPosition(10, 10);
}

void Game2::initEnemies()
{

	this->enemy_texture.loadFromFile("../../assets/mini_game/fly1.png");

	this->enemy.setPosition(100.f, 800.f);
	this->enemy.setTexture(this->enemy_texture);
	// this->enemy.setTextureRect(sf::IntRect(0, 0, 100, 100));
	this->enemy.setScale(sf::Vector2f(0.2f, 0.2f));

	// this->enemy.setFillColor(sf::Color::Red);
	// this->enemy.setOutlineColor(sf::Color::Green);
	// this->enemy.setOutlineThickness(1.f);
}

void Game2::initbox()
{
	this->box.setPosition(100.f, 800.f);
	this->box.setSize(sf::Vector2f(600.f, 100.f));
	this->box.setFillColor(sf::Color::Red);
}

void Game2::initHitbox()
{
	this->hitbox.setPosition(100.f, 800.f);
	this->hitbox.setSize(sf::Vector2f(50.f, 100.f));
	this->hitbox.setFillColor(sf::Color::Green);
}

Game2::Game2(sf::RenderWindow * window)
{
	this->initializeVariables();
	this->initWindow(window);
	this->initFonts();
	this->initHitbox();
	this->initText();
	this->initEnemies();
	this->initbox();
}

Game2::~Game2()
{
	
}

const bool Game2::running()
{
	return this->window->isOpen();
}

const bool Game2::getEndGame()
{
	return this->endGame;
}

const int Game2::getPoints()
{
	return this->points;
}

void Game2::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->endGame = true;
				points = 0;
				return;
			}
			break;
		default:
			break;
		}
	}
}

void Game2::spawnEnemy()
{

	// this->enemy.setPosition(
	// static_cast<float>(rand() % static_cast<int>(this->window->getSize().x)),// - this->enemy.getLocalBounds().width)),
	// static_cast<float>(rand() % static_cast<int>(this->window->getSize().y))// - this->enemy.getLocalBounds().height))
	//);

	// this->enemy.setTexture(sf::Color::Green);
	this->hitbox.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - 200) + 100), 800.f);
	this->enemies.push_back(this->enemy);
}

void Game2::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n"
	   << "Health: " << this->health;
	// std::cout << ss.str();
	this->uiText.setString(ss.str());
}

void Game2::updateEnemies()
{

	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemyspeed = 0;
			this->clock.restart();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 0.1f;
		}
	}

	// Moving and updating enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{

		bool deleted = false;
		float x;
		this->enemyspeed = 19 * sin(this->clock.getElapsedTime().asSeconds() * 4);
		// Center direction for enemy
		if (this->enemies[i].getPosition().x < this->window->getSize().x / 2 - 100)
		{
			x = (this->window->getSize().x / 2 - this->enemies[i].getPosition().x) / 10;
		}
		else if (this->enemies[i].getPosition().x > this->window->getSize().x / 2 + 100)
		{
			x = (this->window->getSize().x / 2 - this->enemies[i].getPosition().x) / 10;
		}
		else if (this->enemies[i].getPosition().x < this->window->getSize().x / 2)
		{
			x = 600;
		}
		else
		{
			x = 200;
		}

		// float y = (this->window->getSize().y / 2 - this->enemies[i].getPosition().y) / 100;
		std::cout << this->enemyspeed << std::endl;
		this->enemies[i].move(this->enemyspeed, 0);

		if (this->flower.getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "health: " << this->health << std::endl;
		}
	}

	// Check if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().intersects(this->hitbox.getGlobalBounds()))
				{
					// Delete the enemy

					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					// Gain points
					this->points += 1;
					std::cout << "points: " << this->points << std::endl;
				}
				else if (this->enemies[i].getGlobalBounds().contains(this->mousePosView) || true)
				{
					// Delete the enemy

					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					// Gain points
					this->health -= 1;
					std::cout << "points: " << this->points << std::endl;
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game2::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		// update mouse position
		this->updateMousePosition();

		this->updateText();

		this->updateEnemies();
	}
	if (this->health <= 0 || this->points >= 20)
	{
		this->endGame = true;
	}
}

void Game2::updateMousePosition()
{
	/*
		return void

		updates the mouse positions:
			mouse position relative to window (Vector2i)
	*/

	this->mousePosWinow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWinow);
}

void Game2::renderEnemies(sf::RenderTarget &target)
{
	target.draw(this->hitbox);
	for (auto &e : this->enemies)
	{
		target.draw(e);
	}
}

void Game2::renderText(sf::RenderTarget &target)
{
	target.draw(this->uiText);
}

void Game2::renderBox(sf::RenderTarget &target)
{
	target.draw(this->box);
}

void Game2::render()
{
	/*
			-clear old frame
			-render obj
			-display frame in window
	*/

	this->window->clear();

	// draw game obj

	this->renderBox(*this->window);

	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();
}
int Game2::startGame(sf::RenderWindow * window)
{
	// Init srand
	srand(static_cast<unsigned>(time(NULL)));

	Game2 game(window);

	// Game loop
	while (game.running() && !game.getEndGame())
	{
		// Update
		game.update();
		// Render
		game.render();
	}
	return game.getPoints();
}
