#include "Bat.h"

Bat::Bat(float init_x, float init_y) : position(init_x, init_y)
{
	bat_shape.setSize(sf::Vector2f(200, 10));
	bat_shape.setPosition(position);
}

sf::FloatRect Bat::GetPosition()
{
	return bat_shape.getGlobalBounds();
}

sf::RectangleShape Bat::GetShape()
{
	return bat_shape;
}

void Bat::MoveLeft(float dt)
{
	velocity -= acceleration;
}

void Bat::MoveRight(float dt)
{
	velocity += acceleration;
}

void Bat::Update(float dt)
{
	bat_shape.setPosition(position);

	if (velocity > max_velocity)
		velocity = max_velocity;
	else if (velocity < -max_velocity)
		velocity = -max_velocity;

	if (velocity > 0.f)
		velocity -= friction;
	else if (velocity < 0.f)
		velocity += friction;

	if (std::abs(velocity) < 0.05f)
		velocity = 0.f;

	position.x += velocity * dt;

}