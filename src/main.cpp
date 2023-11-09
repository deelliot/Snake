#include "../includes/game.h"

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Snake", sf::Style::Default};
    window.setFramerateLimit(60);
    game::Game game(&window);
    sf::Clock clock;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
             if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            {
		        if (game.screen == game::GAME)
                    game.screen = game::PAUSE;
                else
                    game.screen = game::GAME;
            }
            game.handleInput();
        }
        window.clear(sf::Color::Black);
       // sf::Clock;
        game.play();
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
