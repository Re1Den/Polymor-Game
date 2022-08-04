#include "Skritulys.h"

Skritulys::Skritulys(const sf::RenderWindow& window)
{
	this->initShape(window);
	this->type = 's';
}

Skritulys::~Skritulys()
{
}

void Skritulys::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));

	//sf::Color color;
	//color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);

	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(2.f);

	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
		static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
}

const char& Skritulys::getType() const
{
	return this->type;
}

const float& Skritulys::getPosY() const
{
	return this->shape.getPosition().y;
}

const sf::FloatRect Skritulys::getShapeGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Skritulys::moveShape(float x, float y)
{
}

void Skritulys::update()
{

}

void Skritulys::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}