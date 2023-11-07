#ifndef SNAKE_H
# define SNAKE_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics.hpp>
#include "utils.h"

namespace game
{
	class Snake
	{
	public:
		Snake(sf::RenderWindow *); //CONSTRUCTOR
		void onKeyPressed();
		void drawSnake();
		void growSnake();
		void updateSnake();
		bool checkCollision(sf::Vector2f foodLocation);
		bool checkBodyCollision();
		bool checkWindowCollision();
		void setDirection(int x, int y);
	private:
		sf::RenderWindow *window;
		/*snake details*/
		sf::Vector2f head = {WIDTH/2, 0};
		sf::Vector2f direction = {0, 1};
		std::vector<sf::Vector2f> body;
		sf::Color colorBody;
		sf::Color colorHead;
		float scale;
	};
};
	#endif
