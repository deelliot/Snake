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
			void drawMenu();
			void gameOver();
		private:
			sf::RenderWindow *window;
			sf::Font headerFont;
			sf::Font optionsFont;
	};
}

#endif