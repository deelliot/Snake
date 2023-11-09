#include "../includes/snake.h"

game::Snake::Snake(sf::RenderWindow *window)
{
	colorBody = sf::Color(44,67,23);
	colorHead = sf::Color(235, 234, 152);
	scale = SCALE;
	this->window = window;
	resetSnake();
}

void game::Snake::setDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
}

sf::Vector2f game::Snake::getDirection()
{
	return (direction);
}

void game::Snake::growSnake()
{
	sf::Vector2f newSegment;

	newSegment = {head.x, head.y};
	body.push_back(newSegment);
}

void game::Snake::updateSnake()
{
	int i = 0;
	if (body.size() >= 1)
	{
		while (i < body.size() - 1)
		{
			body[i] = body[i + 1];
			i++;
		}
		body[body.size() - 1] = {head.x, head.y};
	}
	head.x += direction.x * scale;
	head.y += direction.y * scale;
}

void game::Snake::drawSnake()
{
	int i = 0;
	this->window->draw(setBox(head, colorHead));
	while (i < body.size())
	{
		this->window->draw(setBox(body[i++], colorBody));
	}
}

void game::Snake::resetSnake()
{
	head = {WIDTH/2, HEIGHT - GAME_HEIGHT};
	direction = {0,1};
	body.clear();

}

bool game::Snake::checkCollision(sf::Vector2f objectPosition)
{
	sf::RectangleShape snakeHead;
	sf::RectangleShape object;

	snakeHead.setPosition(head);
	snakeHead.setSize(sf::Vector2f(SCALE,SCALE));
	object.setPosition(objectPosition);
	object.setSize(sf::Vector2f(SCALE,SCALE));

	return(snakeHead.getGlobalBounds().intersects(object.getGlobalBounds()));
}

bool game::Snake::checkWindowCollision()
{
	if ((head.x + direction.x < WIDTH_OFFSET ||
		head.x + direction.x > GAME_WIDTH + WIDTH_OFFSET - SCALE) ||
		(head.y + direction.y < HEIGHT_OFFSET ||
		head.y + direction.y > GAME_HEIGHT + HEIGHT_OFFSET - SCALE))
		return (true);
	return (false);
}

bool game::Snake::checkBodyCollision()
{
	int i = 0;
	while (i < body.size())
	{
		if (checkCollision(body[i++]))
			return(true);
	}
	return (false);
}