/* NOTES 
* Using Multithreaded Debug DLL for Debug mode only to avoid
* LNK2019 Vector error
*/

#include <SFML/Graphics.hpp>

#include "Display.h"
#include "Bat.h"
#include "Ball.h"

#include <sstream>

const unsigned WIDTH = 1280, HEIGHT = 720;

int score = 0;

int main()
{
	Display display(WIDTH, HEIGHT, "Pong");

	Bat bat(WIDTH / 2, HEIGHT - 10);
	Ball ball(WIDTH / 2, 1);

	sf::Text hud;
	sf::Font font;
	font.loadFromFile("./res/Oswaldesque Regular.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);
	hud.setFillColor(sf::Color::White);

	sf::Event event;

	sf::Clock clock;
	float dt;

	bool move_left = false, move_right = false;

	// This "while" loop goes round and round- perhaps forever
	while (display.IsOpen())
	{

		dt = clock.getElapsedTime().asMicroseconds() * powf(10, -3);
		clock.restart();

		// Event polling
		while (display.GetWindow()->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				display.Close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					display.Close();
					break;
				case sf::Keyboard::Left:
					move_left = true;
					break;
				case sf::Keyboard::Right:
					move_right = true;
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					move_left = false;
					break;
				case sf::Keyboard::Right:
					move_right = false;
					break;
				}
				break;
			}
		}

		ball.CheckCollisions(ball, bat, score, WIDTH, HEIGHT);

		if (move_left)
			bat.MoveLeft(dt);
		else if (move_right)
			bat.MoveRight(dt);

		ball.Update(dt);
		bat.Update(dt);

		std::stringstream ss;
		ss << " Score: " << score;
		hud.setString(ss.str());

		// Clear everything from the last run of the while loop
		display.Clear();

		// Draw our game scene here
		display.GetWindow()->draw(bat.GetShape());
		display.GetWindow()->draw(ball.GetShape());
		display.GetWindow()->draw(hud);

		// Show everything we just drew
		display.Render();
	}

	return 0;
}