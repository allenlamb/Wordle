//
// Created by Allen Lam on 5/8/22.
//

#ifndef SFML_TEST_LETTERGRID_H
#define SFML_TEST_LETTERGRID_H
#include "Typing.h"

class LetterGrid : public sf::Drawable {
private:
    sf::Font font;
    Typing words[6];
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    LetterGrid();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getAttempt() const;
};


#endif //SFML_TEST_LETTERGRID_H
#include "Wordle.h"