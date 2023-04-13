//
// Created by Allen Lam on 4/27/22.
//

#include "FileItem.h"
#include <iostream>
FileItem::FileItem() {
}

FileItem::FileItem(std::string text, sf::Vector2f pos, bool iconType) {
    box.changePos(pos);
    box.changeData(text);
    item = iconType;
    if(iconType) {
        texture.loadFromFile("folder.png");
        icon.setScale({.07,.07});
    }
    else {
        texture.loadFromFile("file.png");
        icon.setScale({.1,.1});
    }
    icon.setTexture(texture);
    icon.setPosition({pos.x+5,pos.y+10});
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(icon);
}


void FileItem::setPosition(sf::Vector2f pos) {
    box.changePos(pos);
    icon.setPosition({pos.x+5,pos.y+10});

}

sf::Vector2f FileItem::getPosition() const {
    return box.getPos();
}

sf::Vector2f FileItem::getSize() const {
    return box.getSize();
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void FileItem::adEventHandler(sf::RenderWindow &window, sf::Event event) {
    box.FileEventHandler(window,event);

}

void FileItem::update() {
    box.FileUpdate();

}

void FileItem::setIcon(bool iconType) {
    item = iconType;
    if(iconType) {
        texture.loadFromFile("folder.png");
        icon.setScale({.07,.07});
    }
    else {
        texture.loadFromFile("file.png");
        icon.setScale({.1,.1});
    }
    icon.setTexture(texture);

}

void FileItem::setText(std::string text) {
    box.changeData(text);
}

void FileItem::setPos(sf::Vector2f pos) {
    icon.setPosition({pos.x+5,pos.y+10});
    box.changePos(pos);
}

bool FileItem::isClick() {
    return box.isClick();

}

bool FileItem::isFile() const {
    return item;
}

std::string FileItem::getString() const {
    return box.getData();
}


void FileItem::setIcon(sf::Sprite& sprite) {
    icon = sprite;
}


