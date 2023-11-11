 #include "../includes/game.h"

game::Game::Game(sf::RenderWindow *window)
{
	this->window = window;
    snake = Snake(window);
    food = Food(window);
    menu = Menu(window);
    screen = game::Screen::START;
    mode = EASY;
    setSpeed();
}

void game::Game::handleInput(sf::Event::EventType eventType, int key)
{
    if (eventType == sf::Event::KeyReleased && key == sf::Keyboard::Space)
	{
		if (screen == game::GAME)
				screen = game::PAUSE;
		else if (screen == END)
            screen = game::START;
        else
			screen = game::GAME;
	}
    else if (eventType == sf::Event::KeyPressed)
    {
        if (screen == game::START)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                selectMode();
        }
        else if (screen == game::GAME)
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
}

void game::Game::selectMode()
{
    switch(mode)
    {
        case game::EASY:
            mode = HARD;
            break;
        case game::HARD:
            mode = PROGRESSIVE;
            break;
        case game::PROGRESSIVE:
            mode = EASY;
            break;
    }
    setSpeed();
}

void game::Game::setSpeed()
{
     switch(mode)
    {
        case game::EASY:
            speed = 100.f;
            break;
        case game::HARD:
            speed = 50.f;
            break;
        case game::PROGRESSIVE:
            speed = 150.f;
            break;
    }
}

void game::Game::increaseSpeed()
{
    speed -= 5;
}

void game::Game::draw()
{
    switch(screen)
        {
            case game::START:
                reset();
                menu.drawStartScreen(mode);
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
        }
        if (snake.checkFoodCollision(food.food))
        {
            food.setRandomLocation();
            menu.changeScore(speed);
            snake.growSnake();
            if (mode == PROGRESSIVE && speed > 10)
                increaseSpeed();
        }
        snake.updateSnake();
    }
}

void game::Game::reset()
{
    snake.resetSnake();
    menu.resetScore();
}