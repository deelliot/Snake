#ifndef UTILS_H
# define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

# define WIDTH 800
# define HEIGHT 600
#define BOX_SIZE 20

static sf::RectangleShape setBox( sf::Vector2f location, sf::Color color )
	{
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
		box.setPosition(location);
		box.setFillColor(color);
		return box;
	}

#endif