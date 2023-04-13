//
// Created by Allen Lam on 4/4/22.
//

#include "DropDownInput.h"

DropDownInput::DropDownInput() {
    box.setOutlineThickness(1);
}

void DropDownInput::defaultSelect(std::string input) {
    menuText = input;
    changeData(menuText);
}

void DropDownInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        click = !click;
    }
    if (click) {
        box.setFillColor(sf::Color::Blue);
        if (MouseEvents<sf::RectangleShape>::mouseClickedWindow(window,event) &&
                !MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
            click = false;
        }
    }
    if (!click) {
        box.setFillColor(sf::Color(31,32,33));
    }
}
void DropDownInput::addEventHandlerOneItem(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        click = true;
    }
    else {
        click = false;
    }
    if (click) {
        box.setFillColor(sf::Color::Blue);
    }
    if (!click) {
        box.setFillColor(sf::Color(31,32,33));
    }
}

bool DropDownInput::getClick() {
    return click;
}

std::string DropDownInput::getMenuText() {
    return menuText;
}


