//
// Created by Allen Lam on 3/25/22.
//

#include "InputBox.h"

InputBox::InputBox(sf::Vector2f pos, sf::Vector2f size) {
   setSize(size);
   setPosition(pos);
}




InputBox::InputBox() {
    setFillColor(sf::Color::Transparent);
    setOutlineThickness(2);

}

void InputBox::clicked() {
    setOutlineColor(sf::Color::Green);
}

void InputBox::unclicked() {
    setOutlineColor(sf::Color::White);
}
