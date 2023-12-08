#ifndef HM_1
#define HM_1
#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 



/**/


class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Mouse positions
	sf::Vector2i mousePosWinow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	std::vector<sf::Sprite> enemies;
	sf::Sprite enemy;
	sf::Texture enemy_texture;
	sf::CircleShape flower;
	sf::Texture flower_texture;
	sf::Sprite flyche;
	sf::Texture flyche_texture;

	//Private funtions
	void initializeVariables();
	void initWindow(sf::RenderWindow *);
	void initFonts();
	void initText();
	void initEnemies();
	void initFlower();
public:
	//Constructors Destructors
	Game(sf::RenderWindow *);
	virtual ~Game();

	//Accessors
	const bool running();
	const bool getEndGame();
	const int getPoints();

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePosition();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderFlower(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();


	static int startGame(sf::RenderWindow *);
};



#endif