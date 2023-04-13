//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_TEXTINPUT_H
#define SFML_TEST_TEXTINPUT_H
#include "GUIComponents.h"
#include "Typing.h"
#include "InputBox.h"
#include "Cursor.h"
class TextInput : public GUIComponents {
public:
    TextInput();
    void setLabel(const std::string& label);
    void setLabelSize(const int& size);
    void setLabelMargin(const sf::Vector2f& margin);
    void setPos(const sf::Vector2f& pos);

    //from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    //from SnapshotInterface
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    std::string getString();
    void setString(std::string str);
private:
    bool undo = false;
    States states;
    InputBox box;
    Letter label;
    Typing typing;
    Cursor cursor;
    sf::Font font;
    bool toggle;
    std::string undoString;
};


#endif //SFML_TEST_TEXTINPUT_H
