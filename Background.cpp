

#include "Background.h"

Background::Background() {
    bg.setPosition({50,115});
    bg.setSize({1650, 495});
    bg.setOutlineThickness(1);

}

void Background::update(sf::Color color, int value) {
    Background::color = color;
    color.a = value;
    bg.setFillColor(color);
}

void Background::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(bg);
}

sf::Color Background::getColor() {
    return bg.getFillColor();
}

