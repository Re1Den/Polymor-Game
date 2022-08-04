#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = hpMax;
	this->wasOnGround = false;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(35.f, 60.f));

	
	texture.loadFromFile("images/hero.png");
	hero.setTexture(texture);

	this->shape.setTexture(&texture);
}

void Player::initPhysics()
{
	//sf::Vector2f velocity;
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.93f;
	//this->gravity = 2.f;
	this->gravity = 1.5f;
	this->velocityMaxY = 15.f;
}

//Constructors and Destructors//
Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);
	this->initVariables();
	this->initShape();
	this->initPhysics();
}

Player::~Player()
{

}

//Accessors
const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

const int& Player::getHp() const
{
	return this->hp;
}
const int& Player::getHpMax() const
{
	return this->hpMax;
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

//Functions
void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;

	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHealtth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;

	if (this->hp > this->hpMax)
		this->hp = hpMax;

}

void Player::updateMovement()
{

}

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;
	
	//Limit Velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//Gravity
	this->velocity.y += (1.0 * this->gravity);
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
	if(std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->shape.move(this->velocity);
}

void Player::updateInput()
{
	//Keyboard input

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape.setScale(-1.0f, 1.0f);
		shape.setOrigin(this->shape.getGlobalBounds().width / 1.f, 0.f);
		this->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		shape.setScale(1.0f, 1.0f);
		shape.setOrigin(0.f, 0.f);
		this->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	
		if (this->mouseHeld == false /*&& wasOnGround == true*/)
		{
			this->mouseHeld = true;
			velocity.y = -30.f;
			this->move(0.f, -1.f);
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(0.f, 1.f);
	}
	else
	{
		this->mouseHeld = false;
		this->wasOnGround = false;
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//bottom
	if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		wasOnGround = true;
	}

}

void Player::update(const sf::RenderTarget* target)
{

	this->updateInput();

	//Window bound collision
	this->updateWindowBoundsCollision(target);
	this->updatePhysics();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
