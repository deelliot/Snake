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
    bool gameState = true;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            snake.onKeyPressed();
        }
        window.clear(sf::Color::Black);
        if (gameState)
        {
            food.drawFood();
            snake.drawSnake();
            if (snake.checkWindowCollision() || snake.checkBodyCollision())
               gameState = false;
            if (snake.checkCollision(food.getLocation()))
            {
                food.setRandomLocation();
                snake.growSnake();
            }
        } else {
            menu.drawGameOver();
        }
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
