//
// Created by Allen Lam on 4/28/22.
//

#ifndef SFML_TEST_SLIDER_H
#define SFML_TEST_SLIDER_H
#include "GUIComponents.h"

class Slider : public GUIComponents {
private:
    sf::Font font;
    sf::Text label;
    sf::RectangleShape line;
    sf::CircleShape circle;
    sf::Text number;
    int value =0;
public:
    Slider();
    Slider(std::string text, int length,sf::Vector2f pos);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    //from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    virtual void backwardEventHandler(sf::RenderWindow& window, sf::Event event);
    void update() override;
    virtual void adjustSlider(int num);
    int getValue();
    //frorm SnapshotInterface
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
    States states;
};


#endif //SFML_TEST_SLIDER_H
