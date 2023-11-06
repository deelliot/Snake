#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../includes/window.h"
#include "../includes/snake.h"

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Snake", sf::Style::Default};
    window.setFramerateLimit(144);
    game::Snake snake(&window);

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
        snake.drawSnake();
        window.display();
    }
}
