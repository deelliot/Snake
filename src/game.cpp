 #include "../includes/game.h"

game::Game::Game(sf::RenderWindow *window)
{
	this->window = window;
    snake = Snake(window);
    food = Food(window);
    menu = Menu(window);
    screen = game::Screen::START;
}

void game::Game::handleInput(sf::Event::EventType eventType, int key)
{
    if (eventType == sf::Event::KeyReleased && key == sf::Keyboard::Space)
	{
		if (screen == game::GAME)
				screen = game::PAUSE;
		else
			screen = game::GAME;
	}
    else if (eventType == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDirection().x != 1)
            snake.setDirection(-1, 0);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& snake.getDirection().x != -1)
            snake.setDirection(1, 0);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& snake.getDirection().y != 1)
            snake.setDirection(0, -1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDirection().y != -1)
            snake.setDirection(0, 1);
    }
}

void game::Game::draw()
{
    switch(screen)
        {
            case game::START:
                menu.drawStartScreen();
                break;
            case game::GAME:
                menu.drawGameScreen();
                food.drawFood();
                snake.drawSnake();
                break;
            case game::PAUSE:
                menu.drawPauseScreen();
                break;
            default:
                menu.drawGameOver();
                break;
        }
}

void game::Game::update()
{

    if (screen == GAME)
    {
        if (snake.checkWindowCollision() || snake.checkBodyCollision())
        {
            screen = game::END;
            snake.resetSnake();
        }
        if (snake.checkCollision(food.getLocation()))
        {
            food.setRandomLocation();
            menu.changeScore();
            snake.growSnake();
        }
        snake.updateSnake();
    }
}