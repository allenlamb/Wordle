//
// Created by Allen Lam on 4/4/22.
//

#ifndef SFML_TEST_DROPDOWNINPUT_H
#define SFML_TEST_DROPDOWNINPUT_H
#include "Item.h"

class DropDownInput : public Item {
private:
    bool click = false;
    std::string menuText;
public:
    DropDownInput();
    bool getClick();
    void defaultSelect(std::string input);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void addEventHandlerOneItem(sf::RenderWindow &window, sf::Event event);
    std::string getMenuText();
};


#endif //SFML_TEST_DROPDOWNINPUT_H
