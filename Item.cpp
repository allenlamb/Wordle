//
// Created by Allen Lam on 4/4/22.
//

#include "Item.h"
#include <iostream>
void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
}

Item::Item() {
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);
    box.setOutlineThickness(0.5);
    box.setOutlineColor(sf::Color::White);
    box.setSize({400,80});
}

void Item::changeData(const std::string& str) {
    data = str;

}

void Item::update() {
    text.setFont(font);
    text.setString(data);
    sf::Vector2f textCenter {box.getGlobalBounds().left +
                             (box.getGlobalBounds().width-text.getGlobalBounds().width)/2,
                             box.getGlobalBounds().top +
                             (box.getGlobalBounds().height-text.getGlobalBounds().height)/2};
    text.setPosition(textCenter);
}

void Item::changePos(sf::Vector2f pos) {
    box.setPosition(pos);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::hovered(box,window)) {
        box.setFillColor(sf::Color::Blue);
    }
    else {
        box.setFillColor(sf::Color(31,32,33));
    }
    if( MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        click = true;
    }
}

void Item::changeSize(sf::Vector2f size, int charaSize) {
    box.setSize(size);
    text.setCharacterSize(charaSize);
}

std::string Item::getData() const {
    return data;
}

bool Item::isClick() {
    return click;
}

void Item::toggleClick() {
    click=false;
}

void Item::FileEventHandler(sf::RenderWindow &window, sf::Event event) {


     if( MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        click = !click;
    }
    else if (click && event.type == sf::Event::MouseButtonPressed && !(MouseEvents<sf::RectangleShape>::mouseClicked(box,window))) {
        click = false;
    }
}
void Item::FileUpdate() {
    update();
    if (click) {
        box.setFillColor(sf::Color::Blue);
    }
    else {
        box.setFillColor(sf::Color(31,32,33));
    }
}

sf::Vector2f Item::getSize() const{
    return box.getSize();
}

sf::Vector2f Item::getPos() const{
    return box.getPosition();
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}


