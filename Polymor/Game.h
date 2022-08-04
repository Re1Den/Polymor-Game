#pragma once

#include "Figura.h"
#include "Skritulys.h"
#include "Kvadratas.h"
#include "Trikampis.h"

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

class Game
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;
	int points;


	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	sf::Texture texture;
	sf::Sprite background;

	std::vector<std::unique_ptr<Figura>> figuros;

	float spawnTimerMaxTriangle;
	float spawnTimerTriangle;
	int triangle;
	int maxTriangle;

	float spawnTimerMaxRectangle;
	float spawnTimerRectangle;
	int rectangle;
	int maxRectangle;

	float spawnTimerMaxCircle;
	float spawnTimerCircle;
	int circle;
	int maxCircle;

	float enemySpeedY;
	float enemySpeedX;
	std:: string level;

	void initVariables();
	void initWindow();

	void initFonts();
	void initText();

public:
	//Constructors & Destructors
	Game();
	~Game();

	//Accessors
	const bool& getEndGame() const;

	//Functions
	const bool running() const;
	void pollEvents();

	void updateEnemies();

	void spawnShapes();
	void moveShapes();
	void updateCollision();
	void updatePlayerCollision();
	void updatePlayer();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);

	void render();

};

