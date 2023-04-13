//
// Created by Allen Lam on 3/23/22.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
    && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) ||
    (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)
    && sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}