#ifndef FOOD_H
# define FOOD_H

#include "utils.h"

namespace game
{
	class Food
	{
		public:
			Food(){};
			Food(sf::RenderWindow *);
			void drawFood();
			void setRandomLocation();
			sf::RectangleShape food;
		private:
			int randomNumber(int lowerLimit, int upperLimit);
			sf::RenderWindow *window;
			sf::Vector2f location;
			sf::Color foodColor;
	};
}

#endif