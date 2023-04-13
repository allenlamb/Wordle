//
// Created by Allen Lam on 4/4/22.
//

#ifndef SFML_TEST_ITEMLIST_H
#define SFML_TEST_ITEMLIST_H
#include <list>
#include "Item.h"
class ItemList : public sf::Drawable {

private:
    std::string selectedItem;
    std::list<Item> list;
    sf::Vector2f size = {200,100};
    sf::Vector2f startingPos = {0,0};
    int charaSize = 50;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
public:
    ItemList();
    void update();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void addItem(std::string item);
    void changePos(sf::Vector2f pos = {0,0});
    void changeSize(sf::Vector2f size, int charaSize);
    void setSelectItem(std::string item);
    int getSize();
    std::string getSelectItem();
    bool isClick(std::string item);
};


#endif //SFML_TEST_ITEMLIST_H
