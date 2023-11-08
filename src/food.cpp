#include "../includes/food.h"

game::Food::Food(sf::RenderWindow *window)
{
	foodColor = sf::Color::Red;
	this->window = window;
	srand(time(0));
	setRandomLocation();
}

void game::Food::setRandomLocation()
{

	int xLowerLimit = floor(WIDTH_OFFSET - 5 / SCALE);
	int yLowerLimit = floor(HEIGHT_OFFSET / SCALE);
	int xUpperLimit = floor((GAME_WIDTH + WIDTH_OFFSET)/  SCALE);
	int yUpperLimit = floor((GAME_HEIGHT + HEIGHT_OFFSET) / SCALE);


	location.x = randomNumber(xLowerLimit, xUpperLimit) * SCALE;
	location.y = randomNumber(yLowerLimit, yUpperLimit) * SCALE;
}

/* returns a random number between the lowerLimit and the upperlimit*/
int game::Food::randomNumber(int lowerLimit, int upperLimit)
{
	int randomNumber;

	randomNumber = rand() % (lowerLimit - upperLimit) + lowerLimit;
	return (randomNumber);
}

void game::Food::drawFood()
{
	this->window->draw(setBox(location, foodColor));
}

sf::Vector2f game::Food::getLocation()
{
	return (location);
}