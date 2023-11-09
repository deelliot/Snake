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
		void draw();
		void update();
		Screen screen;
		void handleInput(sf::Event::EventType eventType, int key);

	private:
		sf::RenderWindow *window;
		Snake snake;
		Food food;
		Menu menu;
	};
}

#endif