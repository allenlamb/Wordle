//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_TYPING_H
#define SFML_TEST_TYPING_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Multitext.h"

class Typing : public sf::Drawable {
private:
    MultiText entry;
    // Holds all text typed into the window
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    // Draws text
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    // Placed in thePoll  Events loop, Detects when a key is pressed on the keyboard
    // and concatenates the character into the sf Text object
    void update();
    // Called outside of poll event loop and used for updates,
    // if any, needed after an event is handled and before the object is drawn
    void setPosition(sf::Vector2f pos);
    void setCharSize(int size);
    std::string getTyped() const;
    float getPosition();
    void setTyped(std::string word);
};






#endif //SFML_TEST_TYPING_H
