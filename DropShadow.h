//
// Created by Allen Lam on 2/12/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef SFML_TEST_DROPSHADOW_H
#define SFML_TEST_DROPSHADOW_H

class DropShadow : public sf::Drawable
{
private:
    sf::Text shadow;
    sf::Color color;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    DropShadow();
    DropShadow(const sf::Text &text,
               const sf::Color &color=sf::Color::Transparent,
               const int &opacity=100,
               const float &scale=0.9);
    void setText (sf::Text text);
    void setScale(const float &scale);
    void setOpacity(const int &opacity);
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f pos);

};
// I implemented methods and constructors that allow the user to adjust the shadow
// I won't allow adjustment of the actual text object in this class
// Adjustments to the text object being shadowed can be done with the outside of this class
// Then, when it's time to draw, I'll use the update function to check and see if anything changed.


#endif //SFML_TEST_DROPSHADOW_H
