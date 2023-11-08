#ifndef UTILS_H
# define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>

# define WIDTH 800
# define HEIGHT 600
# define GAME_WIDTH 600
# define GAME_HEIGHT 440
# define WIDTH_OFFSET 100
# define HEIGHT_OFFSET 80

/*colour codes*/
// # define khaki (44,67,23)
// # define lavender (174, 180, 203)
// # define lemon (235, 234, 152)
// # define brown (112, 93, 64)
// # define beige (178, 179, 150)


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