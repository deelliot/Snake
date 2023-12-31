#ifndef MENU_H
# define MENU_H
#include "utils.h"

namespace game
{
	class Menu
	{
		public:
			Menu(){};
			Menu(sf::RenderWindow *);
			void drawStartScreen(int mode);
			void drawGameScreen();
			void drawPauseScreen();
			void drawGameOver();
			void changeScore(float speed);
			void resetScore();
			void setHighScore();
			//Screen screen;


		private:
			sf::RectangleShape createMenuBorder(sf::Color fillColor);
			sf::RectangleShape createTextbox(sf::Text *textOption);
			sf::Text createText(sf::Font &font, sf::String string, int size);
			sf::RenderWindow *window;
			sf::Font headerFont;
			sf::Font optionsFont;
			int score;
			int highscore;
	};
}

#endif