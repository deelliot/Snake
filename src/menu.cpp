#include "../includes/menu.h"

game::Menu::Menu(sf::RenderWindow *window)
{
    this->window = window;
    if(!headerFont.loadFromFile("assets/headerFont/TechnoRaceItalic.otf"))
        exit(0);
	if (!optionsFont.loadFromFile("assets/Lato/Lato-LightItalic.ttf"))
		exit(0);
	score = 0;
	highscore = 0;
}

void game::Menu::changeScore(float speed)
{
	score += 50 * (1 / speed * 100);
}

void game::Menu::resetScore()
{
	score = 0;
}

void game::Menu::setHighScore()
{
	if (score > highscore)
		highscore = score;
}

void game::Menu::drawStartScreen(int mode)
{
	sf::RectangleShape border = createMenuBorder(sf::Color(44,67,23));
	sf::Text header = createText(headerFont, "SNAKE", 100);
	sf::Text selectMode = createText(optionsFont, "Select play mode:", 40);
	sf::Text easyMode = createText(optionsFont, "Snail", 40);
	sf::Text hardMode = createText(optionsFont, "Mamba", 40);
	sf::Text progressiveMode = createText(optionsFont, "Progressive", 40);
	sf::RectangleShape textBox;


	sf::Vector2f headerPosition = {(border.getPosition().x +
		(border.getSize().x) / 2.f),(border.getPosition().y +
			(border.getSize().y) / 3.f)};
    header.setPosition(headerPosition);
	selectMode.setPosition({headerPosition.x, headerPosition.y + 100});
	easyMode.setPosition({headerPosition.x, headerPosition.y + 150});
	hardMode.setPosition({headerPosition.x, headerPosition.y + 200});
	progressiveMode.setPosition({headerPosition.x, headerPosition.y + 250});
	if(mode == 1)
		textBox = createTextbox(&easyMode);
	else if(mode == 2)
		textBox = createTextbox(&hardMode);
	else
		textBox = createTextbox(&progressiveMode);

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(header);
	window->draw(selectMode);
	window->draw(easyMode);
	window->draw(textBox);
	window->draw(hardMode);
	window->draw(progressiveMode);
}

sf::RectangleShape game::Menu::createTextbox(sf::Text *textOption)
{
	sf::RectangleShape textbox;
	textbox.setSize(sf::Vector2f(textOption->getLocalBounds().width + 10, textOption->getLocalBounds().height + 10));
    textbox.setPosition(textOption->getGlobalBounds().left - 5, textOption->getGlobalBounds().top -5);
    textbox.setFillColor(sf::Color::Transparent);
    textbox.setOutlineColor(sf::Color::White);
    textbox.setOutlineThickness(1);

	return (textbox);
}

void game::Menu::drawGameScreen()
{
	sf::RectangleShape border;
	sf::Vector2f borderSize = { GAME_WIDTH, GAME_HEIGHT};
	std::string scoreString = "Score: " + std::to_string(score);
	sf::Text scoreBoard = createText(headerFont, scoreString, 30);


	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(8.f);
	border.setFillColor(sf::Color(178, 179, 150));
	border.setSize(borderSize);
	border.setPosition(sf::Vector2f(WIDTH/2 - borderSize.x/2,
		HEIGHT/2 - borderSize.y/2));

	scoreBoard.setPosition((border.getPosition().x +
		(border.getSize().x) / 2.f), 560);

	window->draw(border);
	window->draw(scoreBoard);
}

void game::Menu::drawPauseScreen()
{
	sf::RectangleShape border = createMenuBorder(sf::Color(174, 180, 203));
	sf::Text header = createText(headerFont, "Paused", 100);
	sf::Text restart = createText(optionsFont, "Press SPACE to restart", 40);

    sf::Vector2f headerPosition = {(border.getPosition().x +
		(border.getSize().x) / 2.f),(border.getPosition().y +
			(border.getSize().y) / 3.f)};
	header.setPosition(headerPosition);
	restart.setPosition({headerPosition.x, headerPosition.y + 100});

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(header);
	window->draw(restart);
}

void game::Menu::drawGameOver()
{
	sf::RectangleShape border = createMenuBorder(sf::Color::Black);
	sf::Text header = createText(headerFont, "Game Over", 100);
	sf::Text restart = createText(optionsFont, "Press SPACE to restart", 40);
	std::string scoreString = "Score: " + std::to_string(score);
	sf::Text scoreBoard = createText(headerFont, scoreString, 40);
	std::string highScoreString = "High Score: " + std::to_string(highscore);
	sf::Text highScore = createText(headerFont, highScoreString, 40);

	sf::Vector2f headerPosition = {(border.getPosition().x +
		(border.getSize().x) / 2.f),(border.getPosition().y +
			(border.getSize().y) / 3.f)};
	header.setPosition(headerPosition);
	restart.setPosition({headerPosition.x, headerPosition.y + 200});
	scoreBoard.setPosition({headerPosition.x, headerPosition.y + 100});
	highScore.setPosition({headerPosition.x, headerPosition.y + 150});

	window->clear(sf::Color::Black);
	window->draw(border);
	window->draw(header);
	window->draw(restart);
	window->draw(scoreBoard);
	window->draw(highScore);
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
