#pragma once
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include <random>
/**/


class ClickerGame
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Mouse positions
	sf::Vector2i mousePosWinow;
	sf::Vector2f mousePosView;

	//ClickerGame logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//ClickerGame objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private funtions
	void initializeVariables();
	void initWindow(sf::RenderWindow *);
	void initEnemies();
public:
	//Constructors Destructors
	ClickerGame(sf::RenderWindow *);
	virtual ~ClickerGame();

	//Accessors
	const bool running();

	//Functions
	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();

	//Runner
	static void startClickerGame(sf::RenderWindow *);
};

