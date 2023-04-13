//
// Created by Allen Lam on 4/26/22.
//

#ifndef SFML_TEST_MENUBAR_H
#define SFML_TEST_MENUBAR_H
#include "GUIComponents.h"
#include "Dropdown.h"

#include <list>
class MenuBar : public GUIComponents {
private:
    sf::Vector2f pos = {550,0};
    sf::Vector2f size = {0,70};
    float charSize = 30;
    std::list<Dropdown> menulist;
    std::string clicked;
public:
    MenuBar();
    void addMenu(std::string menuTitle);
    void addMenuItem(std::string menuTitle, std::string menuItem);
    std::string menuClick();
    void setMenuClick();
    bool menuClick(int pos);
    bool dropDownClick(int pos);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    //from SnapshotInterface
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    States states;
};


#endif //SFML_TEST_MENUBAR_H
#include "Wordle.h"