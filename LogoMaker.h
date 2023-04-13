//
// Created by Allen Lam on 4/28/22.
//

#ifndef SFML_TEST_LOGOMAKER_H
#define SFML_TEST_LOGOMAKER_H
#include "GUIComponents.h"
#include "Slider.h"
#include "ColorSelector.h"
#include "MenuBar.h"
#include "Dropdown.h"
#include "LogoInput.h"
#include "Background.h"
#include "FileTree.h"
#include <fstream>
class LogoMaker : public GUIComponents {
private:
    Slider tOpacity;
    Slider sOpacity;
    Slider bOpacity;
    Slider skew;
    Slider fontSize;
    Slider textX;
    Slider textY;
    Slider shadowX;
    Slider shadowY;
    ColorSelector font;
    ColorSelector back;
    LogoInput logo;
    Background background;
    MenuBar menu;
    FileTree fontTree;
public:
    LogoMaker();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    //from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void applyUpdates();
    //from SnapshotInterface
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
    void newProject();
    void fontMenuClick();
    void exportMenuClick(sf::RenderWindow& window);
    void saveFile();
    void loadFile();
    States states;
};


#endif //SFML_TEST_LOGOMAKER_H
