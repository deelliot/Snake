#include "../includes/snake.h"

game::Snake::Snake(sf::RenderWindow *window)
{
	length = 1;
	colorBody = sf::Color::Blue;
	colorHead = sf::Color::Yellow;
	scale = 2;
	this->window = window;


	//body.push_back(getRectangleAt(sf::Vector2f(start), colorHead));
}

void game::Snake::drawSnake()
{
	updateSnake();
	this->window->draw(setBox(head, colorHead));
}

void game::Snake::setDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
}

void game::Snake::updateSnake()
{
	head.x += direction.x * scale;
	head.y += direction.y * scale;
}

bool game::Snake::checkCollision(sf::Vector2f objectPosition)
{
	sf::RectangleShape snakeHead;
	sf::RectangleShape object;

	snakeHead.setPosition(head);
	snakeHead.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
	object.setPosition(objectPosition);
	object.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));

	return(snakeHead.getGlobalBounds().intersects(object.getGlobalBounds()));
}