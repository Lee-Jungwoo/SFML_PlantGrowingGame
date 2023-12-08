#include "mini_game_HM_1.h"
void Game::initializeVariables()
{
	this->window = nullptr;

	// Game logics
	this->endGame = false;
	this->points = 0;
	this->health = 10;
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
	this->mouseHeld = false;
}

void Game::initWindow(sf::RenderWindow * window)
{
	

	this->window = window;

	
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("../../assets/Fonts/Font-Medium.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load from file";
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(50);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("None");
	this->uiText.setPosition(10, 10);
}

void Game::initEnemies()
{

	this->enemy_texture.loadFromFile("../../assets/mini_game/fly1.png");

	this->enemy.setPosition(100.f, 100.f);
	this->enemy.setTexture(this->enemy_texture);
	// this->enemy.setTextureRect(sf::IntRect(0, 0, 100, 100));
	this->enemy.setScale(sf::Vector2f(0.1f, 0.1f));

	// this->enemy.setFillColor(sf::Color::Red);
	// this->enemy.setOutlineColor(sf::Color::Green);
	// this->enemy.setOutlineThickness(1.f);
}

void Game::initFlower()
{
	this->flower_texture.loadFromFile("../../assets/mini_game/fertilizer.png");
	this->flower.setRadius(100);
	this->flower.setPosition(
		this->window->getSize().x / 2 - this->flower.getRadius(),
		this->window->getSize().y / 2 - this->flower.getRadius());
	this->flower.setTexture(&this->flower_texture);
	// this->flower.setFillColor(sf::Color::Red);
}

Game::Game(sf::RenderWindow *window)
{
	this->initializeVariables();
	this->initWindow(window);
	this->initFonts();
	this->initText();
	this->initEnemies();
	this->initFlower();
}

Game::~Game()
{
	
}

const bool Game::running()
{
	return this->window->isOpen();
}

const bool Game::getEndGame()
{
	return this->endGame;
}

const int Game::getPoints()
{
	return this->points;
}

void Game::pollEvents()
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
		}
	}
}

void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x)), // - this->enemy.getLocalBounds().width)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y))  // - this->enemy.getLocalBounds().height))
	);

	// this->enemy.setTexture(sf::Color::Green);

	this->enemies.push_back(this->enemy);
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n"
	   << "Health: " << this->health;
	// std::cout << ss.str();
	this->uiText.setString(ss.str());
}

void Game::updateEnemies()
{

	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 8.f;
		}
	}

	// Moving and updating enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{

		bool deleted = false;

		// Center direction for enemy
		float x = (this->window->getSize().x / 2 - this->enemies[i].getPosition().x) / 100;
		float y = (this->window->getSize().y / 2 - this->enemies[i].getPosition().y) / 100;

		this->enemies[i].move(x, y);

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
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					// Delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					// Gain points
					this->points += 1.f;
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

void Game::update()
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

void Game::updateMousePosition()
{
	/*
		return void

		updates the mouse positions:
			mouse position relative to window (Vector2i)
	*/

	this->mousePosWinow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWinow);
}

void Game::renderEnemies(sf::RenderTarget &target)
{
	for (auto &e : this->enemies)
	{
		target.draw(e);
	}
}

void Game::renderText(sf::RenderTarget &target)
{
	target.draw(this->uiText);
}

void Game::renderFlower(sf::RenderTarget &target)
{
	target.draw(this->flower);
}

void Game::render()
{
	/*
			-clear old frame
			-render obj
			-display frame in window
	*/

	this->window->clear();

	// draw game obj

	this->renderFlower(*this->window);

	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();
}
int Game::startGame(sf::RenderWindow * window)
{
	// Init srand
	srand(static_cast<unsigned>(time(NULL)));

	Game game(window);

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
