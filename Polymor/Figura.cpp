#include "Figura.h"

Figura::Figura()
{
	type = '\0';
}

Figura::~Figura()
{
}

void Figura::initShape(const sf::RenderWindow& window)
{
}

const char& Figura::getType() const
{
	return this->type;
}

const float& Figura::getPosY() const
{
	return 0.f;
}

void Figura::moveShape(float x, float y)
{
}

void Figura::update()
{
}

void Figura::render(sf::RenderTarget& target)
{

}
