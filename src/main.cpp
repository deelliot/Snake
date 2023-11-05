#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../includes/window.h"


void menu(sf::RenderWindow *window)
{
    sf::Font gameFont;

    if(!gameFont.loadFromFile("/Users/debbieelliott/Developer/Snake/font/techno-race-italic-font/TechnoRaceItalic-eZRWe.otf"))
        printf("font error");
    sf::Text welcomeMessage;

    welcomeMessage.setFont(gameFont);
    welcomeMessage.setString("Welcome");
    welcomeMessage.setCharacterSize(48);
    welcomeMessage.setFillColor(sf::Color::White);
    welcomeMessage.setPosition((WIDTH)/2, HEIGHT/2);

    window->draw(welcomeMessage);
}

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Snake", sf::Style::Default};
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        menu(&window);
        window.display();
    }
}
