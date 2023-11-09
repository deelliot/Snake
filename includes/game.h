#ifndef GAME_H
# define GAME_H

#include "utils.h"
#include "snake.h"
#include "food.h"
#include "menu.h"



namespace game
{
	enum Screen
	{
		START,
		GAME,
		PAUSE,
		END
	};

	class Game
	{
	public:
		Game(sf::RenderWindow *);
		void play();
		Screen screen;
		void handleInput();

	private:
		sf::RenderWindow *window;
		Snake snake;
		Food food;
		Menu menu;
	};
}

#endif