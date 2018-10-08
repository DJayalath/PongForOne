#include "Display.h"

Display::Display(unsigned width, unsigned height, std::string title) :
	m_width(width), m_height(height),
	m_window(sf::VideoMode(width, height), title) {}
