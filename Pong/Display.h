#pragma once

#include <SFML/Graphics.hpp> // For creating a window
#include <string> // For passing window title

class Display
{
public:

	Display(unsigned width, unsigned height, std::string title);

	const unsigned GetWidth() { return m_width; }
	const unsigned GetHeight() { return m_height; }

	bool IsOpen() { return m_window.isOpen(); }
	void Clear() { m_window.clear(); }
	void Close() { m_window.close(); }
	void Render() { m_window.display(); }
	
	sf::RenderWindow* GetWindow() { return &m_window; }

private:

	const unsigned m_width, m_height;
	sf::RenderWindow m_window;
};

