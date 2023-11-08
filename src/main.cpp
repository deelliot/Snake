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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		        menu.screen = game::GAME;
            snake.handleInput();
        }
        window.clear(sf::Color::Black);
        switch(menu.screen)
        {
            case game::START:
                menu.drawStartScreen();
                break;
            case game::GAME:
                food.drawFood();
                snake.drawSnake();
                if (snake.checkWindowCollision() || snake.checkBodyCollision())
                {
                    menu.screen = game::END;
                    snake.resetSnake();
                }
                if (snake.checkCollision(food.getLocation()))
                {
                    food.setRandomLocation();
                    snake.growSnake();
                }
                break;
            default:
                menu.drawGameOver();
                break;
        }
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
