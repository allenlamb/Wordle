//
// Created by Allen Lam on 2/12/22.
//

#include "DropShadow.h"
DropShadow::DropShadow()
{
    color = sf::Color::White;
}

DropShadow::DropShadow(const sf::Text &text, const sf::Color &color, const int &opacity, const float &scale)
{
    DropShadow::shadow=text;
    setScale(scale);
    if(color == sf::Color::Transparent)
    {
        setColor(text.getFillColor());
    }
    setOpacity(opacity);
}

void DropShadow::setText(sf::Text text) {
    DropShadow::shadow = text;
}

void DropShadow::setOpacity(const int &opacity)
{
    color.a = opacity;
    shadow.setFillColor(color);
}

void DropShadow::setScale(const float &scale)
{
    shadow.setScale(1,-1*scale);
}

void DropShadow::setColor(sf::Color color)
{
    DropShadow::color = color;
}

void DropShadow::setPosition(sf::Vector2f pos) {
    shadow.setPosition(pos);
}

void DropShadow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(shadow);
}

