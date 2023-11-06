#ifndef SNAKE_H
# define SNAKE_H

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics.hpp>

#define BOX_SIZE 20

namespace game {
	class Snake
	{
	public:
		Snake(sf::RenderWindow *); //CONSTRUCTOR
		void drawSnake();
		void setDirection(int x, int y);
		void updateSnake();
	private:
		sf::RenderWindow *screen;

		/*snake details*/
		int length;
		sf::Vector2f head = {0, 0};
		sf::Vector2f direction = {0, 0};
		//std::vector<sf::RectangleShape> body;
		sf::Color colorBody;
		sf::Color colorHead;

		float scale;
	};

};
	#endif
