#include "mini_game_HM.h"

void Game::initializeVariables()
{
	this->window = nullptr;
	

	//Game logics
	this->points = 0;
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
}

void Game::initWindow(sf::RenderWindow * w)
{
	// this->videoMode.height = 1280;
	// this->videoMode.width = 700;
	this->window = w;
	// this->window = new sf::RenderWindow(this->videoMode, "Game1", sf::Style::Titlebar | sf:: Style::Close);

	// this->window->setFramerateLimit(60);
	
}

void Game::initEnemies()
{
	this->enemy.setPosition(100.f, 100.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);


}

Game::Game(sf::RenderWindow * window)
{
	this->initializeVariables();
	this->initWindow(window);
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running()
{
	return this->window->isOpen();
}

void Game::pollEvents() 
{
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			break;
		default:
			break;
		}
	}
}




void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);

	this->enemy.setFillColor(sf::Color::Green);

	this->enemies.push_back(this->enemy);
}

void Game::updateEnemies() 
{
	
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else {
			this->enemySpawnTimer += 1.f;
		}
	}

	for (int i = 0; i < this->enemies.size();i++) {
		bool deleted = false;

		//Center direction for enemy
		float x = (this->window->getSize().x/2 - this->enemies[i].getPosition().x) / 100;
		float y = (this->window->getSize().y/2 - this->enemies[i].getPosition().y) / 100;

		this->enemies[i].move(x,y);

		//Check if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{
				
				this->points += 10;
				deleted = true;
			}
		}

		//Check if bottom
		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			deleted = true;
			
		}

		//Final delete
		if (deleted) {
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void Game::update()
{
	this->pollEvents();

	//update mouse position
	this->updateMousePosition();

	this->updateEnemies();

}

void Game::updateMousePosition() {
	/*
		return void

		updates the mouse positions:
			mouse position relative to window (Vector2i)
	*/

	this->mousePosWinow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWinow);
}

void Game::renderEnemies()
{
	for (auto& e : this->enemies) {
		this->window->draw(e);
	}
}

void Game::render()
{
	/*
			-clear old frame
			-render obj
			-display frame in window
	*/

	this->window->clear();

	//draw game obj
	this->renderEnemies();


	this->window->display();
}
