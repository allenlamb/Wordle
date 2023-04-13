//
// Created by Allen Lam on 3/23/22.
//

#include "Typing.h"
void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    entry.addLetter(event);
}

void Typing::update() {
    entry.update();
}

Typing::Typing() {
}

void Typing::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(entry);
}

void Typing::setPosition(sf::Vector2f pos) {
    entry.setPos(pos);
}

void Typing::setCharSize(int size) {
    entry.setSize(size);
}

std::string Typing::getTyped() const {
    std::string temp;
    std::list<Letter>::const_iterator iter = entry.cbegin();
    for (; iter!= entry.cend();++iter) {
        temp.push_back(static_cast<char>(iter->getString()[0]));
    }
    return temp;
}

float Typing::getPosition() {
    return entry.updateSpacing();

}

void Typing::setTyped(std::string word) {
    entry.setString(word);
}
