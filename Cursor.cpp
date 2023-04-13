//
// Created by Allen Lam on 3/25/22.
//

#include "Cursor.h"

Cursor::Cursor() {
}

void Cursor::update(sf::Vector2f pos) {
    cursor.setPosition(pos);
    if (clock.getElapsedTime().asMilliseconds()>=1000) {
        clock.restart();
    }
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (clock.getElapsedTime().asMilliseconds()<600) {
        window.draw(cursor);
    }


}

void Cursor::setSize(sf::Vector2f size) {
    cursor.setSize(size);

}
