//
// Created by Allen Lam on 4/4/22.
//

#include "ItemList.h"
#include <iostream>
void ItemList::update() {
    int index = 0;
    std::list<Item>::iterator iter = list.begin();
    for (;iter != list.end(); ++iter) {
        iter->changePos({startingPos.x,
                         startingPos.y +
                         (index * size.y)});
        iter->update();
        if (iter->getData() == getSelectItem()) {
            setSelectItem("");
            // omg this fixes my code4
        }
        ++index;
    }
}

void ItemList::addItem(std::string item) {
    Item x;
    x.changeData(item);
    x.changeSize(size,charaSize);
    x.changePos(startingPos);
    list.push_back(x);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    std::list<Item>::const_iterator iter = list.cbegin();
    for (;iter != list.cend(); ++iter) {
        window.draw(*iter);
    }
}

ItemList::ItemList() {
}

void ItemList::changePos(sf::Vector2f pos) {
    startingPos = pos;
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    std::list<Item>::iterator iter = list.begin();
    for (;iter != list.end(); ++iter) {
        iter->addEventHandler(window,event);
        if(iter->isClick()) {
            setSelectItem(iter->getData());
            iter->toggleClick();

        }
    }
}

void ItemList::changeSize(sf::Vector2f size, int charaSize) {
    this->size = size;
    this->charaSize = charaSize;
}

void ItemList::setSelectItem(std::string item) {
    selectedItem = item;
}

std::string ItemList::getSelectItem() {
    return selectedItem;
}

int ItemList::getSize() {
    return list.size();
}

bool ItemList::isClick(std::string item) {


}
