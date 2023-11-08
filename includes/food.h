#ifndef FOOD_H
# define FOOD_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "utils.h"
#include <ctime>

namespace game
{
	class Food
	{
		public:
			Food(sf::RenderWindow *);
			void drawFood();
			void setRandomLocation();
			sf::Vector2f getLocation();
		private:
			int randomNumber(int lowerLimit, int upperLimit);
			sf::RenderWindow *window;
			sf::Vector2f location;
			sf::Color foodColor;
	};
}

#endif