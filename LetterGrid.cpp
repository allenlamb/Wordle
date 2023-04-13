//
// Created by Allen Lam on 5/8/22.
//

#include "LetterGrid.h"

LetterGrid::LetterGrid() {
    font.loadFromFile("HelveticaNeue Bold.ttf");
    for (int i = 0; i < 6; ++i) {
        words[i].setPosition({465,static_cast<float>(170*i + 320)});
        words[i].setCharSize(85);
    }
}

void LetterGrid::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.text.unicode == '\b' || (event.text.unicode >=97 && event.text.unicode <=122 && words[Wordle::getAttempt()].getTyped().size() <5)) {
        words[Wordle::getAttempt()].addEventHandler(window, event);
    }
}

void LetterGrid::update() {
    words[Wordle::getAttempt()].update();
}

void LetterGrid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < 6; ++i) {
        target.draw(words[i]);
    }
}

std::string LetterGrid::getAttempt() const {
    return (words[Wordle::getAttempt()].getTyped());
}
