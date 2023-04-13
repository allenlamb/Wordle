//
// Created by Allen Lam on 5/8/22.
//

#ifndef SFML_TEST_GRID_H
#define SFML_TEST_GRID_H
#include "GUIComponents.h"


class Grid : public sf::Drawable {
public:
    sf::Color gray = sf::Color(58,60,62);
    sf::Color green = sf::Color(76,115,76);
    sf::Color yellow = sf::Color(134,126,74);
    void setColor(std::string str);
    Grid();
private:
    int count =0;
    sf::RectangleShape grid[30];
    sf::Color color[5];
    void addEventHandler(sf::RenderTarget& window, sf::RenderStates staes) const;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_TEST_GRID_H
#include "Wordle.h"