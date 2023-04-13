//
// Created by Allen Lam on 3/23/22.
//

#include "Multitext.h"
#include <iostream>
std::list<Letter>::const_iterator MultiText::cbegin() const {
    return letterList.cbegin();
}

std::list<Letter>::const_iterator MultiText::cend() const {
    return letterList.cend();
}
std::list<Letter>::iterator MultiText::begin() {
    return letterList.begin();
}

std::list<Letter>::iterator MultiText::end() {
    return letterList.end();
}

MultiText::MultiText() {
    font.loadFromFile("HelveticaNeue Bold.ttf");
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    std::list<Letter>::const_iterator iter = cbegin();
    for (; iter!=cend();++iter) {
        window.draw(*iter);
    }
}

void MultiText::addLetter(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !letterList.empty()) {
            letterList.pop_back();
            glyphSpace.pop_back();
            typeString.pop_back();
        }
        else if (event.text.unicode < 128 && event.text.unicode != '\b') {
            Letter x;
            x.setFillColor(sf::Color::White);
            x.setFont(font);
            x.setCharacterSize(charSize);
            x.setString((char)toupper((char)event.text.unicode));
            float setBack = font.getGlyph((char)toupper((char)event.text.unicode),charSize,false).bounds.width/2;
            x.setPosition(startingPos.x+updateSpacing()-setBack,startingPos.y);
            typeString.append(x.getString());
            letterList.push_back(x);
            glyphSpace.push_back(170);

            // orignal code that i have changed to fix for wordle
//            Letter x;
//            x.setFillColor(sf::Color::White);
//            x.setFont(font);
//            x.setCharacterSize(charSize);
//            x.setString((char)toupper((char)event.text.unicode));
//            x.setPosition(startingPos.x+updateSpacing(),startingPos.y);
//            typeString.append(x.getString());
//            letterList.push_back(x);
//            glyphSpace.push_back(font.getGlyph((char)toupper((char)event.text.unicode),charSize,false).advance);
        }
    }
//    std::vector<sf::Color> colors = ColorCoder::colorCode(typeString);
//    std::vector<sf::Color>::iterator colorIter = colors.begin();
//    std::pair<std::list<Letter>::iterator,std::vector<sf::Color>::iterator> iter(begin(),colorIter);
//    for (;iter.first!=end();++iter.first,++iter.second) {
//        iter.first->setFillColor(*iter.second);
//    }
}

void MultiText::setPos(sf::Vector2f pos) {
    startingPos = pos;
}

void MultiText::update() {

}

void MultiText::setSize(int size) {
    charSize = size;
}

float MultiText::updateSpacing() {
    float space = 0;
    std::list<float>::iterator  iter = glyphSpace.begin();
    for (iter; iter!=glyphSpace.end();++iter) {
        space += *iter;
    }
    return space;
}


std::string MultiText::getString() {
    return typeString;
}

void MultiText::setString(std::string word) {
    typeString.clear();
    letterList.clear();
    glyphSpace.clear();
    for (int i = 0; i < word.size(); ++i) {
        Letter x;
        x.setFont(font);
        x.setCharacterSize(charSize);
        x.setString(static_cast<char>(int(word[i])));
        x.setPosition(startingPos.x+updateSpacing(),startingPos.y);
        typeString.append(x.getString());
        letterList.push_back(x);
        glyphSpace.push_back(font.getGlyph((int(word[i])),charSize,false).advance);
    }
}

void MultiText::setFont(std::string name) {
    font.loadFromFile(name);
    std::list<Letter>::iterator iter = begin();
    for (; iter!=end();++iter) {
        iter->setFont(font);
    }

}

void MultiText::setColor(sf::Color color) {
    std::list<Letter>::iterator iter = begin();
    for (; iter!=end();++iter) {
        iter->setFillColor(color);
    }

}
