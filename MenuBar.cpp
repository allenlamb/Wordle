//
// Created by Allen Lam on 4/26/22.
//

#include "MenuBar.h"

void MenuBar::addMenu(std::string menuTitle) {
    Dropdown temp;
    temp.setStartText(menuTitle);
    temp.setPos(pos);
    pos.x+=250;
    menulist.push_back(temp);
}

void MenuBar::addMenuItem(std::string menuTitle, std::string menuItem) {
    auto iter = menulist.begin();
    for (;iter !=menulist.end();++iter) {
        if (iter->getStartText() == menuTitle) {
            iter->addMenuItem(menuItem);
        }
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    auto iter = menulist.begin();
    for (;iter != menulist.end();++iter) {
        window.draw(*iter);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    auto iter = menulist.begin();
    for (;iter != menulist.end();++iter) {
        iter->addEventHandler(window,event);
        }
}

void MenuBar::update() {
    auto iter = menulist.begin();
    for (;iter != menulist.end();++iter) {
        iter->update();
    }
    clicked = menulist.front().getStartText();
}

Snapshot MenuBar::getSnapshot() {
    return Snapshot();
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

MenuBar::MenuBar() {

}

std::string MenuBar::menuClick() {
    return menulist.front().getStartText();
}

bool MenuBar::menuClick(int pos) {
    auto iter = menulist.begin();
    for (int i = 0; i < pos; ++i) {
        ++iter;
    }
    return iter->getClick();

}


void MenuBar::setMenuClick() {
    clicked = "";
}

bool MenuBar::dropDownClick(int pos) {

}
