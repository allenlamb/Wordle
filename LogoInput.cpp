//
// Created by Allen Lam on 4/30/22.
//

#include "LogoInput.h"

void LogoInput::setColor(sf::Color color) {
    output.setColor(color);
}

LogoInput::LogoInput() {
    font.loadFromFile("OpenSans-Bold.ttf");
    output.setFont(font);
}

void LogoInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(input);
    window.draw(output);
    window.draw(shadow);
}

void LogoInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    input.addEventHandler(window,event);
}

void LogoInput::update() {
    input.update();
    output.setString(input.getString());
}

void LogoInput::applyUpdates(int tOpacity, int sOpacity, int skew, int fontSize, int textX, int textY, int shadowX,
                             int shadowY, sf::Color color) {
    output.setString(input.getString());
    output.setCharacterSize(fontSize+30);
    textColor = color;
    output.setPosition({(float) textX,(float) textY});
    textColor.a = tOpacity;
    shadowColor.a = sOpacity;
    output.setColor(textColor);
    shadow.setColor(textColor);
    shadow.setText(output);
    shadow.setScale((skew+20)/30);
    shadow.setOpacity(sOpacity);
    shadow.setPosition({(float) shadowX,(float) shadowY+130});
}

Snapshot LogoInput::getSnapshot() {

}

void LogoInput::applySnapshot(const Snapshot &snapshot) {

}

std::string LogoInput::getString() {
    return input.getString();
}

void LogoInput::setString(std::string word) {
    input.setString(word);
}

void LogoInput::setFont(std::string x) {
    font.loadFromFile(x+".ttf");
    output.setFont(font);
}

