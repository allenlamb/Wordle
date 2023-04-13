//
// Created by Allen Lam on 4/28/22.
//

#include "ColorSelector.h"

ColorSelector::ColorSelector() {

}

ColorSelector::ColorSelector(std::string text, sf::Vector2f pos, sf::Color color) {
    HSV.setPosition({pos.x-1, pos.y + 167});
    HSV.update();
    HSVOutline.setSize({257,257});
    HSVOutline.setFillColor(sf::Color::White);
    HSVOutline.setOutlineThickness(1);
    HSVOutline.setOutlineColor(sf::Color::White);
    HSVOutline.setPosition({pos.x-2,pos.y+166});
    font.loadFromFile("OpenSans-Bold.ttf");
    label.setFont(font);
    label.setPosition(75+pos.x,pos.y);
    label.setCharacterSize(40);
    label.setString(text);
    outLineBox.setOutlineThickness(2);
    outLineBox.setSize({55,55});
    outLineBox.setPosition(pos);
    outLineBox.setFillColor(color);
    outLineBox.setOutlineColor(sf::Color::White);
    colorPalette[0].setFillColor(sf::Color::Red);
    colorPalette[1].setFillColor(sf::Color::Blue);
    colorPalette[2].setFillColor(sf::Color::Green);
    colorPalette[3].setFillColor(sf::Color::Yellow);
    colorPalette[4].setFillColor(sf::Color::Magenta);
    colorPalette[5].setFillColor(sf::Color::Cyan);
    colorPalette[6].setFillColor(sf::Color::White);
    colorPalette[7].setFillColor(sf::Color(31,32,33));
    for (int i = 0; i < 8; ++i) {
        colorPalette[i].setSize({55,55});
        colorPalette[i].setOutlineColor(sf::Color::White);
        colorPalette[i].setOutlineThickness(2);
    }
    for (int i = 0; i < 4; ++i) {
        colorPalette[i].setPosition({pos.x+59*i,pos.y+59});

    }
    for (int i = 4; i < 8; ++i) {
        colorPalette[i].setPosition({pos.x+59*(i-4),pos.y+110});
    }
}

void ColorSelector::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(outLineBox);
    if (HSVDisplay){
        window.draw(HSVOutline);
        window.draw(HSV);
    }

    if(paletteDisplay) {
        for (int i = 0; i < 8; ++i) {
            window.draw(colorPalette[i]);
        }

    }
}

void ColorSelector::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(outLineBox,window)) {
        togglePalette();
    }
    for (int i = 0; i < 8; ++i) {
        if(MouseEvents<sf::RectangleShape>::mouseClicked(colorPalette[i],window)) {
            if (i<6) {
                toggleHSVDisplay();
                HSV.initializePixels(HSV.RGBtoHue(colorPalette[i].getFillColor()));
            }
            else {
                outLineBox.setFillColor(colorPalette[i].getFillColor());
                if (HSVDisplay) toggleHSVDisplay();
                togglePalette();
            }
        }
    }
    if (HSVDisplay && MouseEvents<sf::RectangleShape>::mouseClicked(HSVOutline,window)) {
        outLineBox.setFillColor(HSV.getColor(sf::Mouse::getPosition(window)));
        togglePalette();
        toggleHSVDisplay();
    }
}

void ColorSelector::update() {

}

Snapshot ColorSelector::getSnapshot() {
    return Snapshot();
}

void ColorSelector::applySnapshot(const Snapshot &snapshot) {

}

void ColorSelector::togglePalette() {
    paletteDisplay = !paletteDisplay;
}

sf::Color ColorSelector::getColor() {
    return outLineBox.getFillColor();
}

void ColorSelector::setColor(int x) {
    outLineBox.setFillColor(sf::Color(x));

}

void ColorSelector::toggleHSVDisplay() {
    HSVDisplay = !HSVDisplay;
}
