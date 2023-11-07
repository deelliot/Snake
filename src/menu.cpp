#include "../includes/menu.h"

game::Menu::Menu(sf::RenderWindow *window)
{
    this->window = window;
    if(!headerFont.loadFromFile("../font/headerFont/TechnoRaceItalic.otf"))
        exit(0);
	if (!optionsFont.loadFromFile("../font/Lato/Lato-LightItalic.ttf"))
		exit(0);
}

void game::Menu::drawMenu()
{
	// window->draw();
}

void game::Menu::gameOver()
{
	sf::RectangleShape border;
	sf::Vector2f borderSize = { WIDTH * 0.75, HEIGHT * 0.75};

	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(8.f);
	border.setFillColor(sf::Color::Black);
	border.setSize(borderSize);
	border.setPosition(sf::Vector2f(WIDTH/2 - borderSize.x/2, HEIGHT/2 - borderSize.y/2));

	sf::Text Header;
	Header.setFont(headerFont);
	Header.setCharacterSize(100);
	Header.setString("Game Over");

	Header.setOrigin(Header.getGlobalBounds().getSize() / 2.f + Header.getLocalBounds().getPosition());
    Header.setPosition(border.getPosition() + (border.getSize() / 2.f));

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(Header);
}