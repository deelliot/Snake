#ifndef UTILS_H
# define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

# define WIDTH 800
# define HEIGHT 600
# define GAME_WIDTH WIDTH * 0.75
# define GAME_HEIGHT HEIGHT * 0.75
# define WIDTH_OFFSET (WIDTH - GAME_WIDTH) / 2
# define HEIGHT_OFFSET (HEIGHT - GAME_HEIGHT) / 2
#define SCALE 20

static sf::RectangleShape setBox( sf::Vector2f location, sf::Color color )
	{
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(SCALE,SCALE));
		box.setPosition(location);
		box.setFillColor(color);
		return box;
	}

#endif