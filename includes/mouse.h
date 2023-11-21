#ifndef MOUSE_H
#define MOUSE_H

#include "utils.h"

namespace game
{
	class Mouse
	{
		public:
			Mouse(){};
			Mouse(sf::RenderWindow *);
			void drawMouse(sf::Texture mouseImage);
			void setRandomLocation();
			sf::RectangleShape mouse;
			bool enabled;
		private:
			int randomNumber(int lowerLimit, int upperLimit);
			sf::RenderWindow *window;
			sf::Vector2f location;
			sf::Color mouseColor;
	};
}

#endif