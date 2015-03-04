#ifndef SF_MANAGER
#define SF_MANAGER
#pragma once

#include <SFML\Graphics.hpp>

class c_sf_manager
{
private:
	sf::RenderWindow main_window;

public:

	c_sf_manager()
	{

	}

	c_sf_manager(unsigned int width, unsigned int height)
	{
		main_window.create(sf::VideoMode(width, height), "forger");
	}

	sf::RenderWindow *get_window()
	{
		return &main_window;
	}

};

#endif // SF_MANAGER