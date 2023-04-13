//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_GUICOMPONENTS_H
#define SFML_TEST_GUICOMPONENTS_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include "SnapshotInterface.h"
#include "EventHandler.h"
#include "KeyShortcuts.h"
#include "MouseEvents.h"
#include "History.h"
class GUIComponents :
        public sf::Drawable,
        public sf::Transformable,
        public States,
        public SnapshotInterface,
        public EventHandler {
    //from sf::Drawable
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
    //from SnapshotInterface
    virtual Snapshot getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
    States states;
};

#endif //SFML_TEST_GUICOMPONENTS_H
