#include "Kvadratas.h"


Kvadratas::Kvadratas(const sf::RenderWindow& window)
{
	this->initShape(window);
	this->type = 'k';
}

Kvadratas::~Kvadratas()
{

}

void Kvadratas::initShape(const sf::RenderWindow& window)
{
	float Lenght = static_cast<float>(rand() % 10 + 15);

	this->shape.setSize(sf::Vector2f(Lenght, Lenght));
	this->shape.setRotation(static_cast<float>(rand()));

	//sf::Color color;
	//color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);

	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(2.f);

	this->shape.setFillColor(sf::Color::Green);
	this->shape.setPosition(sf::Vector2f(static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
		static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
}

const char& Kvadratas::getType() const
{
	return this->type;
}

void Kvadratas::moveShape(float x, float y)
{
}

const float& Kvadratas::getPosY() const
{
	return this->shape.getPosition().y;
}

const sf::FloatRect Kvadratas::getShapeGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Kvadratas::update()
{
}

void Kvadratas::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
