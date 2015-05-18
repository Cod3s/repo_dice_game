#include "c_main_menu_state.h"

c_main_menu_state::c_main_menu_state(c_sf_manager* manager) : i_state(manager)
{

}

void c_main_menu_state::initialize()
{
	_shape = sf::CircleShape(100);
	_title_text = sf::String("What am I doing?");

	_shape.setFillColor(sf::Color::Green);
}

void c_main_menu_state::input()
{

}

void c_main_menu_state::update()
{

}

void c_main_menu_state::render()
{
	//h_manager->get_window()->draw(_shape);
	sf::Text test = sf::Text();
	test.setString(_title_text);
	test.setColor(sf::Color::Red);
	

	h_manager->get_window()->draw(test);
}

void c_main_menu_state::shutdown()
{

}