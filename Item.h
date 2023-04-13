//
// Created by Allen Lam on 4/4/22.
//

#ifndef SFML_TEST_ITEM_H
#define SFML_TEST_ITEM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
class Item :
        public sf::Drawable {
protected:
    sf::RectangleShape box;
private:
    bool click = false;
    sf::Font font;
    int charSize = 50;
    std::string data = "Sample Text";
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Text text;
public:
    Item();
    std::string getData() const;
    void update();
    void changeData(const std::string& str);
    void changePos(sf::Vector2f pos);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void FileEventHandler(sf::RenderWindow& window, sf::Event event);
    void FileUpdate();
    void changeSize(sf::Vector2f size, int charaSize = 0);
    bool isClick();
    void toggleClick();
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPos() const;
};


#endif //SFML_TEST_ITEM_H
