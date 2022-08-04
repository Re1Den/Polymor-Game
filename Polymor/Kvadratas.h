#pragma once
#include "Figura.h"
class Kvadratas :
	public Figura
{
private:

	sf::RectangleShape shape;

public:

	Kvadratas(const sf::RenderWindow& window);
	virtual ~Kvadratas();

	//SFML
	void initShape(const sf::RenderWindow& window);
	const char& getType() const;
	const float& getPosY() const;
	void moveShape(float x, float y);
	const sf::FloatRect getShapeGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};

