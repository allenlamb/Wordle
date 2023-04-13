//
// Created by Allen Lam on 5/6/22.
//

#ifndef SFML_TEST_HSVCOLORSELECT_H
#define SFML_TEST_HSVCOLORSELECT_H
#include "GUIComponents.h"
#include <SFML/Graphics.hpp>
class HSVColorSelect : public sf::Drawable {
private:
    sf::Vector2f initPos;
    sf::VertexArray points;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    HSVColorSelect();
    HSVColorSelect(sf::Vector2f pos);
    float RGBtoHue(sf::Color color);
    void initializePixels(double hue);
    void update();
    sf::Color getColor(sf::Vector2<int> pos);
    void setPosition(sf::Vector2f pos);
};


#endif //SFML_TEST_HSVCOLORSELECT_H
