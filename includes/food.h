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
			void foodLocation();
		private:
			int randomNumber(int upperLimit);
			sf::RenderWindow *window;
			sf::Vector2f location;
			sf::Color foodColor;
	};
}

#endif