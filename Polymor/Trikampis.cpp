#include "Trikampis.h"


Trikampis::Trikampis(const sf::RenderWindow& window)
{
	this->initShape(window);
	this->type = 't';
}

Trikampis::~Trikampis()
{

}

void Trikampis::initShape(const sf::RenderWindow& window)
{
	//float Lenght = static_cast<float>(rand() % 10 + 15);

	this->shape.setRadius(static_cast<float>(rand() % 10 + 15));
	this->shape.setPointCount(3);
	this->shape.setRotation(static_cast<float>(rand()));

	//sf::Color color;
	//color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);

	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(2.f);

	this->shape.setFillColor(sf::Color::Red);
	//this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width), //random x and y
	//	static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
	this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width), 0.f));
}

const char& Trikampis::getType() const
{
	return this->type;
}

const float& Trikampis::getPosY() const
{
	return this->shape.getPosition().y;
}

void Trikampis::moveShape(float x, float y)
{
	shape.move(x, y);
	shape.rotate(0.2f);
}

const sf::FloatRect Trikampis::getShapeGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Trikampis::update()
{
}

void Trikampis::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
