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
			void drawStartScreen();
			void drawGameOver();
		private:
			sf::RectangleShape createMenuBorder(sf::Color fillColor);
			sf::RectangleShape createButtonBorder(sf::Color fillColor,
				sf::Vector2f borderSize, sf::Vector2f position);
			sf::Text createText(sf::Font &font, sf::String string, int size);
			sf::RenderWindow *window;
			sf::Font headerFont;
			sf::Font optionsFont;
	};
}

#endif