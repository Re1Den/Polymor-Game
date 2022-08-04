#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;

	float movementSpeed;

	int hp;
	int hpMax;
	int points;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	sf::Texture texture;
	sf::Sprite hero;

	bool mouseHeld;
	bool wasOnGround;

	void initVariables();
	void initShape();
	void initPhysics();

public:

	//Constructors and Destructors//
	Player(float x = 400.f, float y = 800.f);
	virtual ~Player();


	//Accessors
	const sf::RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	const sf::FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();


	//Functions
	void takeDamage(const int damage);
	void gainHealtth(const int health);

	void updatePhysics();
	void updateMovement();
	void move(const float dir_x, const float dir_y);

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

