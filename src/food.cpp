#include "../includes/food.h"

game::Food::Food(sf::RenderWindow *window)
{
	foodColor = sf::Color(112, 93, 64);
	this->window = window;
	srand(time(0));
	setRandomLocation();
	food = (setBox(location, foodColor));
	food.setOrigin(food.getGlobalBounds().getSize() /
		2.f + food.getLocalBounds().getPosition());
	food.setRotation(0.f);
}

void game::Food::setRandomLocation()
{

	int xLowerLimit = floor(WIDTH_OFFSET / SCALE);
	int yLowerLimit = floor(HEIGHT_OFFSET / SCALE);
	int xUpperLimit = floor((GAME_WIDTH + WIDTH_OFFSET)/ SCALE);
	int yUpperLimit = floor((GAME_HEIGHT + HEIGHT_OFFSET) / SCALE);


	location.x = randomNumber(xLowerLimit, xUpperLimit) * SCALE + SCALE/2;
	location.y = randomNumber(yLowerLimit, yUpperLimit) * SCALE + SCALE/2;
	food.setPosition(location);
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
	food.rotate(10.f);
	this->window->draw(food);
}

sf::Vector2f game::Food::getLocation()
{
	return (location);
}