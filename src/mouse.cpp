#include "../includes/mouse.h"

game::Mouse::Mouse(sf::RenderWindow *window)
{
	this->window = window;
	srand(time(0));
	setRandomLocation();
	enabled = false;
	mouse.setSize({40, 20});
	mouse.setFillColor(sf::Color(174, 180, 203, 128));
}

void game::Mouse::setRandomLocation()
{

	int xLowerLimit = floor(WIDTH_OFFSET / SCALE);
	int yLowerLimit = floor(HEIGHT_OFFSET / SCALE);
	int xUpperLimit = floor((GAME_WIDTH + WIDTH_OFFSET)/ SCALE);
	int yUpperLimit = floor((GAME_HEIGHT + HEIGHT_OFFSET) / SCALE);


	location.x = randomNumber(xLowerLimit, xUpperLimit) * SCALE;
	location.y = randomNumber(yLowerLimit, yUpperLimit) * SCALE;
	mouse.setPosition(location);
}

int game::Mouse::randomNumber(int lowerLimit, int upperLimit)
{
	int randomNumber;

	randomNumber = rand() % (lowerLimit - upperLimit) + lowerLimit;
	return (randomNumber);
}

void game::Mouse::drawMouse(sf::Texture mouseImage)
{
	if (enabled)
	{
		mouse.setTexture(&mouseImage);
		this->window->draw(mouse);
	}
}
