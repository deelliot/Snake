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

	enum Mode
	{
		EASY = 1,
		HARD = 2,
		PROGRESSIVE = 3
	};

	class Game
	{
	public:
		Game(sf::RenderWindow *);
		void draw();
		void update();
		Screen screen;
		void handleInput(sf::Event::EventType eventType, int key);
		Mode mode;
		float speed;
	private:
		sf::RenderWindow *window;
		Snake snake;
		Food food;
		Menu menu;
		int score;
		void selectMode();
		void setSpeed();
		void increaseSpeed();
		void reset();
	};
}

#endif