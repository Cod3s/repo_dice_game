#include <SFML\Graphics.hpp>
#include "global_managers\sf_manager.h"

#include "global_managers\memory\memory_manager.h"
#include "states\c_main_menu_state.h"

int main()
{
	c_sf_manager sf_manager(1080, 720);
	sf::RenderWindow *window_handle = sf_manager.get_window();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	c_memory_manager mem_manager;
	mem_manager.initialize();

	c_main_menu_state main_menu = c_main_menu_state(&sf_manager);
	main_menu.initialize();

	while (window_handle->isOpen())
	{
		sf::Event _event;
		while (window_handle->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				window_handle->close();
			}

			// Input
			main_menu.input();
		}

		// update
		main_menu.update();

		// render

		window_handle->clear();
		main_menu.render();
		window_handle->display();
	}

	mem_manager.shutdown();
	main_menu.shutdown();

	return 0;
}