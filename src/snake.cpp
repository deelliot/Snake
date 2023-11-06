#include "../includes/snake.h"

sf::RectangleShape getRectangleAt( sf::Vector2f location, sf::Color color )
	{
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
		box.setPosition(location);
		box.setFillColor(color);
		return box;
	}

game::Snake::Snake(sf::RenderWindow *window)
{
	length = 1;
	colorBody = sf::Color::Blue;
	colorHead = sf::Color::Yellow;
	scale = 5;
	this->window = window;


	//body.push_back(getRectangleAt(sf::Vector2f(start), colorHead));
}

void game::Snake::drawSnake()
{
	updateSnake();
	this->window->draw(getRectangleAt(head, colorHead));
}

void game::Snake::setDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
}

void game::Snake::updateSnake()
{
	head.x += direction.x;
	head.y += direction.y;
}