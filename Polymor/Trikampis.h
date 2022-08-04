#pragma once
#include "Figura.h"
class Trikampis :
	public Figura
{
private:
	sf::CircleShape shape;


public:

	Trikampis(const sf::RenderWindow& window);
	virtual ~Trikampis();


	//SFML
	void initShape(const sf::RenderWindow& window);
	const char& getType() const;
	const float& getPosY() const;
	void moveShape(float x, float y);
	const sf::FloatRect getShapeGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};

