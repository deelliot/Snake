#include "../includes/food.h"

game::Food::Food(sf::RenderWindow *window)
{
	foodColor = sf::Color::Red;
	this->window = window;
	srand(time(0));
	foodLocation();
}

void game::Food::foodLocation()
{
	location.x = randomNumber(WIDTH - 1);
	location.y = randomNumber(HEIGHT - 1);
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
	this->window->draw(getRectangleAt(location, foodColor));
}