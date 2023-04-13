//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_MULTITEXT_H
#define SFML_TEST_MULTITEXT_H
#include <list>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include "ColorCoder.h"
#include <ctype.h>

class MultiText : public sf::Drawable {
private:
    std::string typeString;
    sf::Font font;
    std::list<float> glyphSpace;
    std::list<Letter> letterList;
    int charSize = 60;
    sf::Vector2f startingPos = {1,1};
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
public:
    float updateSpacing();
    std::list<Letter>::const_iterator cbegin() const;
    std::list<Letter>::const_iterator cend() const;
    std::list<Letter>::iterator begin();
    std::list<Letter>::iterator end();
    MultiText();
    std::string getString();
    void addLetter(sf::Event event);
    void setPos(sf::Vector2f pos);
    void setSize(int size);
    void update();
    void setString(std::string word);
    void setFont(std::string name);
    void setColor(sf::Color color);
};

#endif //SFML_TEST_MULTITEXT_H
