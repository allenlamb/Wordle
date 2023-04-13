//
// Created by Allen Lam on 4/28/22.
//

#ifndef SFML_TEST_COLORSELECTOR_H
#define SFML_TEST_COLORSELECTOR_H
#include "GUIComponents.h"
#include "HSVColorSelect.h"
class ColorSelector : public GUIComponents{
private:
    sf::Font font;
    sf::RectangleShape outLineBox;
    sf::RectangleShape HSVOutline;
    sf::Text label;
    sf::RectangleShape colorPalette[9];
    bool paletteDisplay = false;
    bool HSVDisplay = false;
    HSVColorSelect HSV;
public:
    ColorSelector();
    ColorSelector(std::string text, sf::Vector2f pos, sf::Color color);
    void setColor(int x);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const ;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    //from SnapshotInterface
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    States states;
    void togglePalette();
    void toggleHSVDisplay();
    sf::Color getColor();

};


#endif //SFML_TEST_COLORSELECTOR_H
