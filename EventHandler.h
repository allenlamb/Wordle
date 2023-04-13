//
// Created by Allen Lam on 3/23/22.
//
#ifndef SFML_TEST_EVENTHANDLER_H
#define SFML_TEST_EVENTHANDLER_H
#include <SFML/Graphics.hpp>
struct EventHandler {
    virtual void addEventHandler(sf::RenderWindow& window,
                                 sf::Event event) = 0;
    virtual void update() = 0;
};
#endif //SFML_TEST_EVENTHANDLER_H
