
//
// Created by Allen Lam on 3/23/22.
//
#include "Dropdown.h"

void Dropdown::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(selected);
    if (state.isEnabled(CLICK)) {
        window.draw(list);
    }
}

void Dropdown::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(list.getSize() ==0) {
        selected.addEventHandlerOneItem(window,event);
    }
    else {
        selected.addEventHandler(window,event);
        if (state.isEnabled(CLICK) && list.getSize() !=0) {
            list.addEventHandler(window,event);
        }
        if (selected.getClick()) {
            state.enableState(CLICK);
        }
        else if (!selected.getClick()&&list.getSize()!=0){
            state.disableState(CLICK);
        }
    }



//    if (KeyShortcuts::isUndo()) {
//        applySnapshot(History::topHistory().snapshot);
//        History::popHistory();
//    }
}

Dropdown::Dropdown() {
    setPos(pos);
    setSize(size,charaSize);
    selected.defaultSelect(startText);
    list.setSelectItem(startText);
//    Snapshot x;
//    x.setInfo(selected.getMenuText());
//    HistoryNode s;
//    s.snapshot=x;
//    History::pushHistory(s);
}

void Dropdown::setPos(sf::Vector2f pos) {
    selected.changePos({pos.x, pos.y});
    list.changePos({pos.x,pos.y+size.y});
}

void Dropdown::setSize(sf::Vector2f size, int charaSize) {
    selected.changeSize(size,charaSize);
    list.changeSize(size,charaSize);
}

void Dropdown::addMenuItem(std::string item) {
    list.addItem(item);
}

void Dropdown::update() {
    selected.update();
    list.update();
}

Snapshot Dropdown::getSnapshot() {
    return Snapshot();
}

void Dropdown::applySnapshot(const Snapshot &snapshot) {
    selected.defaultSelect(snapshot.getInfo());
    list.setSelectItem(snapshot.getInfo());

}

void Dropdown::changeMenuText() {
    std::cout<<selected.getMenuText();

}

void Dropdown::setStartText(std::string text) {
    startText = text;
    selected.defaultSelect(startText);
    list.setSelectItem(startText);
}

std::string Dropdown::getStartText() {
    return list.getSelectItem();
}

bool Dropdown::getClick() {
    return selected.getClick();
}


