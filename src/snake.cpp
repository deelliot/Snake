#include "../includes/snake.h"

game::Snake::Snake(sf::RenderWindow *window)
{
	colorBody = sf::Color::Blue;
	colorHead = sf::Color::Yellow;
	scale = SCALE;
	this->window = window;
	resetSnake();
}

void game::Snake::setDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
}

void game::Snake::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction.x != 1)
		setDirection(-1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& direction.x != -1)
		setDirection(1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& direction.y != 1)
		setDirection(0, -1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction.y != -1)
		setDirection(0, 1);

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
	updateSnake();
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
	if ((head.x < WIDTH_OFFSET || head.x > GAME_WIDTH + WIDTH_OFFSET - 1) ||
		(head.y < HEIGHT_OFFSET - 5 || head.y > GAME_HEIGHT + HEIGHT_OFFSET))
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