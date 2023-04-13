//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_DROPDOWN_H
#define SFML_TEST_DROPDOWN_H
#include "GUIComponents.h"
#include "DropDownInput.h"
#include "ItemList.h"
class Dropdown : public GUIComponents
{
private:
    std::string clicked;
    DropDownInput selected;
    ItemList list;
    sf::Vector2f pos = {100,0};
    sf::Vector2f size = {250,60};
    int charaSize = 30;
    std::string startText = "None Selected";
public:
    Dropdown();
    void setPos(sf::Vector2f pos);
    void setSize(sf::Vector2f size, int charaSize);
    void addMenuItem(std::string item);
    void changeMenuText();
    void setStartText(std::string text);
    std::string getStartText();
    bool getClick();


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    //from SnapshotInterface
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    States state;

};


#endif //SFML_TEST_DROPDOWN_H
