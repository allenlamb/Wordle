//
// Created by Allen Lam on 4/30/22.
//

#ifndef SFML_TEST_BACKGROUND_H
#define SFML_TEST_BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable {
private :
    sf::RectangleShape bg;
    sf::Color color;
public:
    Background();
    void update(sf::Color color, int value);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Color getColor();

};


#endif //SFML_TEST_BACKGROUND_H
