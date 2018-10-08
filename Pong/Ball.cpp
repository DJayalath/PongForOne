#include "Ball.h"
#include "Bat.h"

Ball::Ball(float init_x, float init_y) : position(init_x, init_y)
{
	ball_shape.setSize(sf::Vector2f(10, 10));
	ball_shape.setPosition(position);
}

sf::FloatRect Ball::GetPosition()
{
	return ball_shape.getGlobalBounds();
}

sf::RectangleShape Ball::GetShape()
{
	return ball_shape;
}

float Ball::GetXVelocity()
{
	return x_velocity;
}

void Ball::ReboundSides()
{
	x_velocity = -x_velocity;
}

void Ball::ReboundBatOrTop(bool bat_collision)
{
	position.y -= (y_velocity * 30);
	y_velocity = -y_velocity;

	if (bat_collision)
	{
		x_velocity *= velocity_multiplier;
		y_velocity *= velocity_multiplier;
	}
}

void Ball::HitBottom()
{
	y_velocity = -0.2f;

	if (x_velocity < 0)
		x_velocity = -0.2f;
	else
		x_velocity = 0.2f;

	position.y -= 20;
}

void Ball::Update(float dt)
{
	// Update the ball position variables
	position.y += y_velocity * dt;
	position.x += x_velocity * dt;

	// Move the ball and the bat
	ball_shape.setPosition(position);
}

void Ball::CheckCollisions(Ball& ball, Bat& bat, int& score, int width, int height)
{
	// Handle ball hitting the bottom
	if (ball.GetPosition().top > height)
	{
		// reverse the ball direction
		ball.HitBottom();

		// reset the score
		score = 0;

	}

	// Handle ball hitting top
	if (ball.GetPosition().top < 0)
	{
		ball.ReboundBatOrTop();
	}

	// Handle ball hitting sides
	if (ball.GetPosition().left < 0 || ball.GetPosition().left + 10 > width)
	{
		ball.ReboundSides();
	}

	// Has the ball hit the bat?
	if (ball.GetPosition().intersects(bat.GetPosition()))
	{
		// Hit detected so reverse the ball and score a point
		ball.ReboundBatOrTop(true);
		score++;
	}
}
