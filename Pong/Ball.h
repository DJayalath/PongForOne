#pragma once

#include <SFML/Graphics.hpp>

class Bat;

class Ball
{
public:

	Ball(float init_x, float init_y);

	sf::FloatRect GetPosition();
	sf::RectangleShape GetShape();

	float GetXVelocity();

	void ReboundSides();
	void ReboundBatOrTop(bool bat_collision = false);
	void HitBottom();
	void CheckCollisions(Ball& ball, Bat& bat, int& score, int width, int height);
	void Update(float dt);

private:

	sf::Vector2f position;
	sf::RectangleShape ball_shape;

	const float velocity_multiplier = 1.1f;

	float x_velocity = .2f;
	float y_velocity = .2f;

};