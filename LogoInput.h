//
// Created by Allen Lam on 4/30/22.
//

#ifndef SFML_TEST_LOGOINPUT_H
#define SFML_TEST_LOGOINPUT_H
#include "GUIComponents.h"
#include "TextInput.h"
#include "Multitext.h"
#include "DropShadow.h"
class LogoInput : public GUIComponents{
private:
    TextInput input;
    sf::Text output;
    sf::Font font;
    DropShadow shadow;
    sf::Color textColor = sf::Color::White;
    sf::Color shadowColor = sf::Color::White;
public:
    LogoInput();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    void applyUpdates(int tOpacity, int sOpacity, int skew,int fontSize,
                      int textX, int textY, int shadowX, int shadowY, sf::Color color);
    //from SnapshotInterface
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    States states;
    void setColor(sf::Color color);
    std::string getString();
    void setString(std::string word);
    void setFont(std::string x);
};


#endif //SFML_TEST_LOGOINPUT_H
