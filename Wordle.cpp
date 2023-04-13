//
// Created by Allen Lam on 5/8/22.
//

#include "Wordle.h"
int Wordle::attempt=0;
bool Wordle::animate=false;
Wordle::Wordle() {
    geniusBox.setFillColor(sf::Color(72,70,72));
    geniusBox.setSize({365,130});
    geniusBox.setPosition({617,220});
    shareButton.setFillColor(sf::Color(76,115,76));
    shareButton.setSize({400,140});
    shareButton.setPosition(800-shareButton.getGlobalBounds().width/2,1342);
    font1.loadFromFile("HelveticaNeue Bold.ttf");
    shareText.setFont(font1);
    shareText.setString("SHARE");
    shareText.setCharacterSize(80);
    shareText.setPosition({800-shareText.getGlobalBounds().width/2,1360});
    genius.setFont(font1);
    genius.setCharacterSize(80);
    int num = rand() % 323;
    font.loadFromFile("ChunkFive-Regular.otf");
    titleText = "Wordle " + std::to_string(num);
    title.setString(titleText);
    title.setFont(font);
    title.setCharacterSize(100);
    title.setPosition({800-title.getGlobalBounds().width/2,100});
    menu.addMenu("New");
    menu.addMenu("Custom");
    randAnswer(num);
}

void Wordle::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (menu.menuClick(0)) {
        newGame();
    }
    if (menu.menuClick(1)) {
        NewWordle();
        NewWordle();
    }
    if(!animate) {
        menu.addEventHandler(window, event);
        if (!score.isSolve()) {
            letters.addEventHandler(window, event);
            if (event.type == sf::Event::KeyReleased && Wordle::getAttempt() <= 5 && letters.getAttempt().size() == 5) {
                if (event.key.code == sf::Keyboard::Enter) {
                    attemptText = score.attemptResult(letters.getAttempt());
                    animate = true;
                }
            }
        }
    }
    if(shareButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) &&
    event.type == sf::Event::MouseButtonReleased) {
            score.scoreFile(titleText);
        shareText.setString("SHARED!");
        shareText.setPosition({800-shareText.getGlobalBounds().width/2,1360});
        }
}
void Wordle::update() {
    menu.update();
    letters.update();
    if (animate) {
        grid.setColor(attemptText);
        if (!animate) {
            Wordle::addAttempt();
        }
    }
    if (attempt == 6 && !score.isSolve()) {
        genius.setString(score.getAnswer());
        genius.setPosition({800-genius.getGlobalBounds().width/2,230});
    }
    else if (score.isSolve()) {
        genius.setString("GENIUS");
        genius.setPosition({800-genius.getGlobalBounds().width/2,230});
    }
}

void Wordle::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (animate) {
        sf::Clock timer;
        window.draw(grid);
        while (timer.getElapsedTime().asMilliseconds()<320) {
        }
        timer.restart();
    }
    else {
        window.draw(grid);
    }
    window.draw(title);
    window.draw(menu);
    window.draw(letters);
    if (score.isSolve() && !animate) {
        window.draw(shareButton);
        window.draw(shareText);
        window.draw(geniusBox);
        window.draw(genius);
    }
    if (attempt == 6 && !score.isSolve() && !animate) {
        window.draw(shareButton);
        window.draw(shareText);
        window.draw(geniusBox);
        window.draw(genius);
    }
}

void Wordle::addAttempt() {
    ++attempt;
}

int Wordle::getAttempt() {
    return attempt;
}

void Wordle::newGame() {
    Wordle *x = new Wordle;
    resetAttempt();
    *this = *x;
}

bool Wordle::getAnimate()  {
    return animate;
}

void Wordle::disableAnimate() {
    animate = false;
}

void Wordle::resetAttempt() {
    attempt =0;
}

void Wordle::NewWordle() {
    Wordle *x = new Wordle;
    resetAttempt();
    std::ifstream fin("Custom.txt");
    std::string line;
    getline(fin,line);
    if (line.size() != 5) {
        x->randAnswer(stoi(line));
        x->titleText = "Wordle " + line;
        x->title.setString(titleText);
    }
    else {
        x->score.setAnswer(line);
        x->title.setString("Custom Wordle");
        x->titleText = "Custom Wordle";
    }
    x->title.setPosition({800-title.getGlobalBounds().width/2,100});
    fin.close();
    *this = *x;

}

void Wordle::randAnswer(int num) {
    std::ifstream fin("Answers.txt");
    std::string line;
    getline(fin,line);
    for (int i = 0; i < 323 - num; ++i) {
        getline(fin,line);
    }
    std::string capital = line;
    for (auto & c: capital) c = toupper(c);
    score.setAnswer(capital);
    fin.close();
}



