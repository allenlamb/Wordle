//
// Created by Allen Lam on 4/28/22.
//

#include "Slider.h"

Slider::Slider() {

}
Slider::Slider(std::string text, int length, sf::Vector2f pos) {
    font.loadFromFile("OpenSans-Bold.ttf");
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(40);
    label.setFillColor(sf::Color::White);
    label.setPosition(pos);
    line.setSize({(float)length,5});
    line.setPosition({pos.x+label.getGlobalBounds().width,pos.y+23});
    line.setFillColor(sf::Color::White);
    circle.setRadius(15);
    circle.setPosition({line.getGlobalBounds().left,pos.y+10});
    number.setFont(font);
    number.setCharacterSize(30);
    number.setPosition(line.getGlobalBounds().width+line.getGlobalBounds().left+10,pos.y+8);
    number.setString("0");
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(label);
    window.draw(line);
    window.draw(circle);
    window.draw(number);
}



void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    number.setString(std::to_string((int)(circle.getGlobalBounds().left-line.getGlobalBounds().left)));
    value = (int) (circle.getGlobalBounds().left-line.getGlobalBounds().left);
    if(MouseEvents<sf::CircleShape>::mouseClicked(circle,window)) {
        states.toggleState(CLICK);
        circle.setFillColor(sf::Color::White);
    }
    if(states.isEnabled(CLICK) &&
    sf::Mouse::getPosition(window).x>=line.getGlobalBounds().left+9 &&
            sf::Mouse::getPosition(window).x<=line.getGlobalBounds().left + line.getGlobalBounds().width) {
        circle.setPosition((float)sf::Mouse::getPosition(window).x-10,circle.getPosition().y);
        circle.setFillColor(sf::Color::Cyan);
    }

}

void Slider::backwardEventHandler(sf::RenderWindow &window, sf::Event event) {
    number.setString(std::to_string(255-(int)(circle.getGlobalBounds().left-line.getGlobalBounds().left)));
    value = (int) (circle.getGlobalBounds().left-line.getGlobalBounds().left);
    if(MouseEvents<sf::CircleShape>::mouseClicked(circle,window)) {
        states.toggleState(CLICK);
        circle.setFillColor(sf::Color::White);
    }
    if(states.isEnabled(CLICK) &&
       sf::Mouse::getPosition(window).x>=line.getGlobalBounds().left+9 &&
       sf::Mouse::getPosition(window).x<=line.getGlobalBounds().left + line.getGlobalBounds().width) {
        circle.setPosition((float)sf::Mouse::getPosition(window).x-10,circle.getPosition().y);
        circle.setFillColor(sf::Color::Cyan);
    }
}

void Slider::update() {


}

Snapshot Slider::getSnapshot() {
    return Snapshot();
}

void Slider::applySnapshot(const Snapshot &snapshot) {

}

int Slider::getValue() {
    return value;
}

void Slider::adjustSlider(int num) {
    circle.setPosition(line.getGlobalBounds().left+num,circle.getPosition().y);
}
