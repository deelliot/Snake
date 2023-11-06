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
	location.x = randomNumber(WIDTH/SCALE) * SCALE;
	location.y = randomNumber(HEIGHT/SCALE) * SCALE;
}

/* returns a random number between 0 and the upperlimit*/
int game::Food::randomNumber(int upperLimit)
{
	int randomNumber;

	randomNumber = rand() % upperLimit;
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