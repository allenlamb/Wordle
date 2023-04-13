//
// Created by Allen Lam on 5/8/22.
//

#include "Grid.h"

Grid::Grid() {
    sf::Color blank = sf::Color(123,114,103);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            grid[5*i+j].setFillColor(sf::Color(31,32,33));
            grid[5*i+j].setOutlineColor(blank);
            grid[5*i+j].setOutlineThickness(3);
            grid[5*i+j].setSize({150,150});
            grid[5*i+j].setPosition({static_cast<float>(170*j+390),static_cast<float>(170*i+300)});
        }
    }
}

void Grid::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < 30; ++i) {
        window.draw(grid[i]);
    }


}

void Grid::setColor(std::string str) {
    if(str[count] == 'g') {
        grid[Wordle::getAttempt()*5 + count].setFillColor(green);
        grid[Wordle::getAttempt()*5+count].setOutlineColor(green);
    }
    else if(str[count] == 'y') {
        grid[Wordle::getAttempt()*5 + count].setFillColor(yellow);
        grid[Wordle::getAttempt()*5+count].setOutlineColor(yellow);
    }
    else if (str[count] == 'n') {
        grid[Wordle::getAttempt()*5 + count].setFillColor(gray);
        grid[Wordle::getAttempt()*5+count].setOutlineColor(gray);
    }
    if (count ==5) {
        sf::Clock timer;
        while (timer.getElapsedTime().asMilliseconds() < 400) {

        }
        Wordle::disableAnimate();
        count = 0;
    }
    else {
        ++count;
    }
}

