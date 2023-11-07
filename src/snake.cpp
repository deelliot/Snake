#include "../includes/snake.h"

game::Snake::Snake(sf::RenderWindow *window)
{
	colorBody = sf::Color::Blue;
	colorHead = sf::Color::Yellow;
	scale = SCALE;
	this->window = window;
}

void game::Snake::drawSnake()
{
	int i = 0;
	updateSnake();
	this->window->draw(setBox(head, colorHead));
	while (i < body.size())
	{
		this->window->draw(setBox(body[i++], colorBody));
	}
}

void game::Snake::setDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
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

void game::Snake::growSnake()
{
	sf::Vector2f newSegment;

	newSegment = {head.x, head.y};
	body.push_back(newSegment);
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
	if ((head.x < 0 || head.x > WIDTH - 1) || (head.y < 0 || head.y > HEIGHT - 1))
		return (true);
	return (false);
}