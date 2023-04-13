//
// Created by Allen Lam on 4/27/22.
//

#ifndef SFML_TEST_FILEITEM_H
#define SFML_TEST_FILEITEM_H
#include "Item.h"
class FileItem : public sf::Drawable {
public:
    FileItem();
    FileItem(std::string text, sf::Vector2f pos, bool iconType);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::FloatRect getGlobalBounds() const;
    virtual void adEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setIcon(bool iconType);
    void setIcon(sf::Sprite& sprite);
    void setText(std::string text);
    void setPos(sf::Vector2f pos);
    bool isClick();
    bool isFile() const;
    std::string getString() const;
private:
    sf::Sprite icon;
    sf::Texture texture;
    Item box;
    bool item;
    float padding = 5;
};


#endif //SFML_TEST_FILEITEM_H
