//
// Created by Allen Lam on 5/8/22.
//

#ifndef SFML_TEST_WORDLE_H
#define SFML_TEST_WORDLE_H
#include "MenuBar.h"
#include "Grid.h"
#include "LetterGrid.h"
#include "Score.h"
#include "MouseEvents.h"
#include <fstream>
class Wordle : public  sf::Drawable{
private:
    sf::String attemptText;
    sf::String titleText;
    sf::RectangleShape geniusBox;
    sf::Text genius;
    sf::RectangleShape shareButton;
    sf::Text shareText;
    sf::Font font;
    sf::Font font1;
    sf::Text title;
    LetterGrid letters;
    MenuBar menu;
    Grid grid;
    Score score;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    static int attempt;
    void newGame();
    static bool animate;
    void resetAttempt();
    void NewWordle();
    void randAnswer(int num);
public:
    Wordle();

    static void addAttempt();
    static int getAttempt();
    static bool getAnimate();
    static void disableAnimate();
    //from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();


};


#endif //SFML_TEST_WORDLE_H
