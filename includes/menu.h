#ifndef MENU_H
# define MENU_H
#include "utils.h"

namespace game
{
	// enum Screen
	// {
	// 	START,
	// 	GAME,
	// 	PAUSE,
	// 	END
	// };

	class Menu
	{
		public:
			Menu(){};
			Menu(sf::RenderWindow *);
			void drawStartScreen();
			void drawGameScreen();
			void drawPauseScreen();
			void drawGameOver();
			void changeScore();
			//Screen screen;


		private:
			sf::RectangleShape createMenuBorder(sf::Color fillColor);
			sf::RectangleShape createButtonBorder(sf::Color fillColor,
				sf::Vector2f borderSize, sf::Vector2f position);
			sf::Text createText(sf::Font &font, sf::String string, int size);
			sf::RenderWindow *window;
			sf::Font headerFont;
			sf::Font optionsFont;
			int score;
	};
}

#endif