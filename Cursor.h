//
// Created by Allen Lam on 3/25/22.
//

#ifndef SFML_TEST_CURSOR_H
#define SFML_TEST_CURSOR_H
#include <SFML/Graphics.hpp>

class Cursor : public sf::Drawable {
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
public:
    Cursor();
    void setSize(sf::Vector2f size);
    void update(sf::Vector2f pos);



};


#endif //SFML_TEST_CURSOR_H
