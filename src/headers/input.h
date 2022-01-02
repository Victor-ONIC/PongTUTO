#pragma once

#include <SFML/Graphics.hpp>

class Input {

    struct Button {
        bool left, right, up, down, escape;
    };

public:
    Input();

    Button GetButton() const;
    void InputHandler(sf::Event event, sf::RenderWindow &window);
    
private:
    Button button;

};