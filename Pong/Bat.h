#pragma once

#include <SFML/Graphics.hpp>

class Bat
{
public:

	Bat(float init_x, float init_y);

	sf::FloatRect GetPosition();
	sf::RectangleShape GetShape();

	void MoveLeft(float dt);
	void MoveRight(float dt);

	void Update(float dt);

private:

	sf::Vector2f position;
	sf::RectangleShape bat_shape;

	float acceleration = 0.1f;
	float friction = 0.01f;
	float velocity = 0.f;
	const float max_velocity = 1.f;

};

