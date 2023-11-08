#include "../includes/menu.h"

game::Menu::Menu(sf::RenderWindow *window)
{
    this->window = window;
    if(!headerFont.loadFromFile("../font/headerFont/TechnoRaceItalic.otf"))
        exit(0);
	if (!optionsFont.loadFromFile("../font/Lato/Lato-LightItalic.ttf"))
		exit(0);
	screen = game::Screen::START;
}

void game::Menu::drawStartScreen()
{
	sf::RectangleShape border = createMenuBorder(sf::Color(0,154,23));
	sf::Text header = createText(headerFont, "SNAKE", 100);
	sf::Text start = createText(optionsFont, "Press SPACE to start", 40);


	sf::Vector2f headerPosition = {(border.getPosition().x + (border.getSize().x) / 2.f),
		(border.getPosition().y + (border.getSize().y) / 3.f)};
    header.setPosition(headerPosition);
	start.setPosition({headerPosition.x, headerPosition.y + 100});

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(header);
	window->draw(start);
}

void game::Menu::drawGameScreen()
{
	sf::RectangleShape border = createMenuBorder(sf::Color(0,154,23));
	// sf::Text header = createText(headerFont, "SNAKE", 100);
	// sf::Text start = createText(optionsFont, "Press SPACE to start", 40);


	// sf::Vector2f headerPosition = {(border.getPosition().x + (border.getSize().x) / 2.f),
	// 	(border.getPosition().y + (border.getSize().y) / 3.f)};
    // header.setPosition(headerPosition);
	// start.setPosition({headerPosition.x, headerPosition.y + 100});

	//window->clear(sf::Color::Black);
	window->draw(border);
	// window->draw(header);
	// window->draw(start);
}

void game::Menu::drawGameOver()
{
	sf::RectangleShape border = createMenuBorder(sf::Color::Black);
	sf::Text header = createText(headerFont, "Game Over", 100);
	sf::Text restart = createText(optionsFont, "Press SPACE to restart", 40);

    sf::Vector2f headerPosition = (border.getPosition() + (border.getSize()) / 2.f);
	header.setPosition(headerPosition);
	restart.setPosition({headerPosition.x, headerPosition.y + 100});

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(header);
	window->draw(restart);
}

sf::RectangleShape game::Menu::createMenuBorder(sf::Color fillColor)
{
	sf::RectangleShape border;
	sf::Vector2f borderSize = { WIDTH * 0.75, HEIGHT * 0.75};

	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(8.f);
	border.setFillColor(fillColor);
	border.setSize(borderSize);
	border.setPosition(sf::Vector2f(WIDTH/2 - borderSize.x/2,
		HEIGHT/2 - borderSize.y/2));
	return (border);
}

sf::Text game::Menu::createText(sf::Font &font, sf::String string, int size)
{
	sf::Text text;

	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(string);
	text.setOrigin(text.getGlobalBounds().getSize() /
		2.f + text.getLocalBounds().getPosition());
	return (text);
}
