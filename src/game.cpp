 #include "../includes/game.h"

game::Game::Game(sf::RenderWindow *window)
{
	this->window = window;
    snake = Snake(window);
    food = Food(window);
    menu = Menu(window);
    screen = game::Screen::START;
}

void game::Game::handleInput()
{
	snake.handleInput();
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