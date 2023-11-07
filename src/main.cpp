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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                snake.setDirection(-1, 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                snake.setDirection(1, 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                snake.setDirection(0, -1);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                snake.setDirection(0, 1);
        }
        window.clear(sf::Color::Black);
        food.drawFood();
        snake.drawSnake();
        if (snake.checkCollision(food.getLocation()))
        {
            food.setRandomLocation();
            snake.growSnake();
        }
        if (snake.checkWindowCollision())
            menu.gameOver();
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
