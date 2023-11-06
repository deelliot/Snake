#ifndef MENU_H
# define MENU_H
#include <SFML/Graphics.hpp>
#include "utils.h"

namespace game
{
	class Menu
	{
		public:
			Menu(sf::RenderWindow *);
		private:
		sf::RenderWindow *window;


	};
}

#endif