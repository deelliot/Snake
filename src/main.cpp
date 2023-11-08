#include "../includes/utils.h"
#include "../includes/snake.h"
#include "../includes/food.h"
#include "../includes/menu.h"
#include <SFML/System/Time.hpp>

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Snake", sf::Style::Default};
    window.setFramerateLimit(60);
    game::Snake snake(&window);
    game::Food food(&window);
    game::Menu menu(&window);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
             if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            // if (sf::Keyboard::isKeyReleased(sf::Keyboard::Space))
            {
		        if (menu.screen == game::GAME)
                    menu.screen = game::PAUSE;
                else
                    menu.screen = game::GAME;
            }
            snake.handleInput();
        }
        window.clear(sf::Color::Black);
        switch(menu.screen)
        {
            case game::START:
                menu.drawStartScreen();
                break;
            case game::GAME:
                menu.drawGameScreen();
                if (snake.checkWindowCollision() || snake.checkBodyCollision())
                {
                    menu.screen = game::END;
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
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
