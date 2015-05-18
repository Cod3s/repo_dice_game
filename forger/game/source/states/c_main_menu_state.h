#ifndef C_MAIN_MENU_STATE
#define C_MAIN_MENU_STATE
#pragma once

#include "i_state.h"
#include <SFML\Graphics.hpp>

class c_main_menu_state : public i_state
{
private:
	sf::CircleShape _shape;
	sf::String _title_text;

public:
	c_main_menu_state(c_sf_manager* manager);
	void initialize();
	void input();
	void update();
	void render();
	void shutdown();
};

#endif // C_MAIN_MENU_STATE