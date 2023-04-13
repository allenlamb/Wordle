//
// Created by Allen Lam on 3/25/22.
//

#ifndef SFML_TEST_INPUTBOX_H
#define SFML_TEST_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "StateEnum.h"

class InputBox : public sf::RectangleShape {
public:
    InputBox(sf::Vector2f pos, sf::Vector2f size);
    void clicked();
    void unclicked();
    InputBox();
private:
    StateEnum boxState;
};


#endif //SFML_TEST_INPUTBOX_H
