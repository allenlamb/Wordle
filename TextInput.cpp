//
// Created by Allen Lam on 3/23/22.
//

#include "TextInput.h"

void TextInput::setLabel(const std::string& label) {
    this->label.setString(label);
}

void TextInput::setLabelSize(const int& size) {
    label.setCharacterSize(size);
}

void TextInput::setLabelMargin(const sf::Vector2f& margin) {
}

void TextInput::setPos(const sf::Vector2f& pos) {
    label.setPosition(pos);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(box);
    window.draw(typing);
    window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        states.enableState(CLICK);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClickedWindow(window,event)&&
    !MouseEvents<sf::RectangleShape>::mouseClicked(box,window)) {
        states.disableState(CLICK);
    }
    if (states.isEnabled(CLICK)) {
        undo = false;
        typing.addEventHandler(window, event);
    }
    if (KeyShortcuts::isUndo()) {
        undoString=History::topHistory().snapshot.getInfo();
        applySnapshot(History::topHistory().snapshot);
        History::popHistory();
    }
}

void TextInput::update() {
    if (states.isEnabled(CLICK)) {
        box.clicked();
        typing.update();
        cursor.update({label.getGlobalBounds().width + typing.getPosition()-45, 670});
    }
    else {
        box.unclicked();
    }
    if (History::topHistory().snapshot.getInfo() != typing.getTyped()&& typing.getTyped()!=undoString) {
        Snapshot s;
        s.setInfo(typing.getTyped());
        HistoryNode h;
        h.snapshot = s;
        History::pushHistory(h);
    }
}
Snapshot TextInput::getSnapshot() {
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    typing.setTyped(snapshot.getInfo());
}

TextInput::TextInput() {
    HistoryNode h;
    h.snapshot.setInfo("");
    History::pushHistory(h);
    font.loadFromFile("OpenSans-Bold.ttf");
    label.setString("Logo Text");
    label.setCharacterSize(20);
    label.setFont(font);
    label.setPosition({45,635});
    typing.setPosition({50,665});
    cursor.setSize({6,70});
    box.setSize({1650,85});
    box.setPosition({50, 665});
}

std::string TextInput::getString() {
    return typing.getTyped();
}

void TextInput::setString(std::string str) {
    typing.setTyped(str);
}
