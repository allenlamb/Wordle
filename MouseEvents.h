//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_MOUSEEVENTS_H
#define SFML_TEST_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
template <class T>
class MouseEvents {
private:
    // determine if double click or triple clicked occured
    static sf::Clock clock;
    static int clickMouse;
public:
    //returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);
    //returns true of the mouse clicks anywhere in the window
    static bool mouseClickedWindow(sf::RenderWindow& window, sf::Event event);
    //returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();
    //returns true if the mouse has been triple clicked
    static bool mouseTripleClick();
    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);
    static bool hovered(T& object, sf::RenderWindow& window);

};
#include "MouseEvents.cpp"
#endif //SFML_TEST_MOUSEEVENTS_H
