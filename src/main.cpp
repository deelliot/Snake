#include "../includes/game.h"

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Snake", sf::Style::Default};
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    game::Game game(&window);
    sf::Clock clock;
    sf::Time nextTickTime = sf::milliseconds(100);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            game.handleInput(event.type, event.key.code);
        }
        window.clear(sf::Color::Black);

        if (clock.getElapsedTime() >= nextTickTime)
        {
            game.update();
            nextTickTime = clock.getElapsedTime() + sf::milliseconds(50);

        }
        game.draw();
        window.display();
    }
}
