//
// Created by Allen Lam on 3/28/22.
//
#ifndef SFML_TEST_MOUSEEVENTS_CPP
#define SFML_TEST_MOUSEEVENTS_CPP
#include "MouseEvents.h"
#include "iostream"
template <class T>
sf::Clock MouseEvents<T>::clock;

template <class T>
int MouseEvents<T>::clickMouse;
template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left)
            && object.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
}

template<class T>
bool MouseEvents<T>::mouseClickedWindow(sf::RenderWindow &window, sf::Event event) {
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left)
    && sf::Mouse::getPosition(window).x>0
    && sf::Mouse::getPosition(window).y>0
    && sf::Mouse::getPosition(window).x<window.getSize().x
    && sf::Mouse::getPosition(window).y<window.getSize().y);
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if(clickMouse == 0) {
            clock.restart();
        }
        ++clickMouse;
        }
    if(clickMouse >= 2 ) {
        clickMouse = 0;
        return (clock.getElapsedTime().asMilliseconds()<=500.f);
    }
}

template<class T>
bool MouseEvents<T>::mouseTripleClick() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if(clickMouse >1) {
            clock.restart();
        }
        ++clickMouse;
    }
    if(clickMouse >= 3 ) {
        clickMouse = 0;
        return (clock.getElapsedTime().asMilliseconds()<=500.f);
    }
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && hovered(object,window)) {
        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            }
        return(hovered(object,window));
    }
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    return (object.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
}

#endif //SFML_TEST_MOUSEEVENTS_CPP