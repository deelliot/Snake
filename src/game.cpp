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


void game::Game::play()
{
    switch(screen)
        {
            case game::START:
                menu.drawStartScreen();
                break;
            case game::GAME:
                menu.drawGameScreen();
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
                food.drawFood();
                snake.drawSnake();
                snake.updateSnake();
                break;
            case game::PAUSE:
                menu.drawPauseScreen();
                break;
            default:
                menu.drawGameOver();
                break;
        }
}