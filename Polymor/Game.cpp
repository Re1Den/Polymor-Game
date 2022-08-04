#include "Game.h"


void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMaxTriangle = 20.f;
	this->spawnTimerTriangle = this->spawnTimerMaxTriangle;
	this->maxTriangle = 10;
	this->points = 0;

	this->spawnTimerMaxRectangle = 10.f;
	this->spawnTimerRectangle = this->spawnTimerMaxRectangle;
	this->rectangle = 0;
	this->maxRectangle = 1;

	this->spawnTimerMaxCircle = 15.f;
	this->spawnTimerCircle = this->spawnTimerMaxCircle;
	this->circle = 0;
	this->maxCircle= 5;

	this->enemySpeedX = 0.f;
	this->enemySpeedY = 2.f;
	this->level = "Zero";

}

void Game::initWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Polymor", sf::Style::Close | sf::Style::Titlebar, settings);
	this->window->setFramerateLimit(60);

	texture.loadFromFile("images/background.png");
	background.setTexture(texture);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME::INNITFONTS::COULD NOT LOADPixellettersFull.ttf\n";
	}
}

void Game::initText()
{
	//Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(25);

	//End game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(sf::Vector2f(35, 200));
	this->endGameText.setOutlineColor(sf::Color::White);
	this->endGameText.setOutlineThickness(1.f);
	this->endGameText.setString("YOU ARE DEAD, EXIT THE GAME!");
}

Game::Game()
{
	this->initVariables();
	this->initWindow();

	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

//Functions//

const bool Game::running() const
{
	return this->window->isOpen();//&& this->endGame == false;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateEnemies()
{
	if (points == 10)
	{
		this->spawnTimerMaxTriangle = 20.f;
		this->maxTriangle = 10;

		this->enemySpeedX = 0.f;
		this->enemySpeedY = 3.f;

		level = "One";
	}
	else if (points == 20)
	{
		this->spawnTimerMaxTriangle = 10.f;
		this->maxTriangle = 12;

		this->enemySpeedX = 1.f;
		this->enemySpeedY = 4.f;

		level = "Two";

	}
	else if (points == 30)
	{
		this->spawnTimerMaxTriangle = 10.f;
		this->maxTriangle = 14;

		this->enemySpeedX = -1.f;
		this->enemySpeedY = 5.f;

		level = "Three";

	}
	else if (points == 40)
	{
		this->spawnTimerMaxTriangle = 10.f;
		this->maxTriangle = 16;

		this->enemySpeedX = 1.f;
		this->enemySpeedY = 5.5f;

		level = "Four";
	}
}

void Game::spawnShapes()
{
	/*Triangle*/
	//Timer 
	if (this->spawnTimerTriangle < this->spawnTimerMaxTriangle)
		this->spawnTimerTriangle += 1.f;
	//Spawner
	else
	{
		if (this->triangle < this->maxTriangle)
		{
			this->figuros.emplace_back(new Trikampis(*this->window));
			triangle++;
			this->spawnTimerTriangle = 0.f;
		}
	}

	
	//Rectangle
	//Timer 
	if (this->spawnTimerRectangle < this->spawnTimerMaxRectangle)
		this->spawnTimerRectangle += 1.f;

	//Spawner
	else
	{
		if (this->rectangle < this->maxRectangle)
		{
			
			this->figuros.emplace_back(new Kvadratas(*this->window));
			rectangle++;
			this->spawnTimerRectangle = 0.f;
		}
	}

	//Circle
	//Timer 
	if (this->spawnTimerCircle < this->spawnTimerMaxCircle)
		this->spawnTimerCircle += 1.f;

	//Spawner
	else
	{
		if (this->circle < this->maxCircle)
		{
			this->figuros.emplace_back(new Skritulys(*this->window));
			circle++;
			this->spawnTimerCircle = 0.f;
		}
	}
	
}

void Game::moveShapes()
{
	//Move triangles 
	for (int i = 0; i < this->figuros.size(); i++)
	{
		if (this->figuros[i]->getType() == 't')			//If trikampis
		{
			//bool deleted = false;
			this->figuros[i]->moveShape(enemySpeedX, enemySpeedY);

			//If the enemy is past the bottom of the screen
			if (this->figuros[i]->getPosY() > this->window->getSize().y)
			{
				this->figuros.erase(this->figuros.begin() + i);
				triangle--;

			}
		}
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (int i = 0; i < figuros.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->figuros[i]->getShapeGlobalBounds()))
		{
			switch (this->figuros[i]->getType())
			{
			case 's':
				this->points++;
				updateEnemies();
				circle--;
				break;

			case 't':
				this->player.takeDamage(1);
				triangle--;
				break;

			case 'k':
				this->player.gainHealtth(1);
				rectangle--;
				break;
			}
			//Remove the ball
			this->figuros.erase(this->figuros.begin() + i);
		}

	}
}

void Game::updatePlayerCollision()
{
	//Collision bottom of the screen
	if (this->player.getGlobalBounds().top + this->player.getGlobalBounds().height >= window->getSize().y)
	{
		this->player.resetVelocityY();
		this->player.setPosition(
			this->player.getGlobalBounds().left,
			this->window->getSize().y - this->player.getGlobalBounds().height);

	}
	
}

void Game::updatePlayer()
{
	this->player.update(this->window);

	this->updatePlayerCollision();

	if (this->player.getHp() <= 0)
		this->endGame = true;
}

void Game::updateGui()
{
	std::stringstream ss;

	ss << " Points: " << this->points << '\n'
		<< " Health: " << this->player.getHp() << " / " << this->player.getHpMax() << '\n' 
		<< " Level: " << this->level;
	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->spawnShapes();
		this->moveShapes();
		this->updateCollision();
		this->updatePlayer();
		this->updateGui();
	}
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();
	this->window->draw(background);
	
	//Render Player
	this->player.render(this->window);

	//Render Shapes
	for (auto &i : this->figuros)
	{
		i->render(*this->window);
	}

	//Render gui
	this->renderGui(this->window);

	//Render end text
	if (this->endGame)
		this->window->draw(this->endGameText);

	this->window->display();
}
