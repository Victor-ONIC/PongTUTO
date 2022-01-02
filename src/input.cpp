#include "input.h"

Input::Input() {

    button.left = false;
    button.right = false;
    button.up = false;
    button.down = false;
    button.escape = false;

}

Input::Button Input::GetButton() const {

    return button;

}

void Input::InputHandler(sf::Event event, sf::RenderWindow &window) {

    if (event.type == sf::Event::Closed) {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed) {

        switch (event.key.code) {
            case sf::Keyboard::Escape:
                button.escape = true;
                break;

            case sf::Keyboard::Left:
                button.left = true;
                break;

            case sf::Keyboard::Right:
                button.right = true;
                break;
            
            case sf::Keyboard::Up:
                button.up = true;
                break;

            case sf::Keyboard::Down:
                button.down = true;
                break;
        }

    }

    if (event.type == sf::Event::KeyReleased) {

        switch (event.key.code) {
            case sf::Keyboard::Escape:
                button.escape = false;
                break;

            case sf::Keyboard::Left:
                button.left = false;
                break;

            case sf::Keyboard::Right:
                button.right = false;
                break;
            
            case sf::Keyboard::Up:
                button.up = false;
                break;

            case sf::Keyboard::Down:
                button.down = false;
                break;
        }

    }

}