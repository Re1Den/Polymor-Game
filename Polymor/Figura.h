#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Figura
{
protected:
	char type;

public:

	Figura();
	virtual ~Figura();

	virtual void initShape(const sf::RenderWindow& window);
	virtual const char& getType() const;
	virtual const float& getPosY() const;
	virtual void moveShape(float x, float y);
	virtual const sf::FloatRect getShapeGlobalBounds() const = 0;
	virtual void update();
	virtual void render(sf::RenderTarget& target);

};


