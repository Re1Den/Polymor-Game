#pragma once
#include "Figura.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Skritulys :
	public Figura
{
private:
	sf::CircleShape shape;

public:

	Skritulys(const sf::RenderWindow& window);
	virtual ~Skritulys();

	void initShape(const sf::RenderWindow& window);
	const char& getType() const;
	const float& getPosY() const;
	void moveShape(float x, float y);
	const sf::FloatRect getShapeGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};

