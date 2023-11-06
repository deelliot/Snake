#ifndef UTILS_H
# define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

# define WIDTH 800
# define HEIGHT 600
#define SCALE 40

static sf::RectangleShape setBox( sf::Vector2f location, sf::Color color )
	{
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(SCALE,SCALE));
		box.setPosition(location);
		box.setFillColor(color);
		return box;
	}

#endif