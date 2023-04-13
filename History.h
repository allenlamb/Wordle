//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_HISTORY_H
#define SFML_TEST_HISTORY_H
#include "SnapshotInterface.h"
#include "GUIComponents.h"
#include "HistNode.h"
#include <stack>


class History {
private:
    static std::stack<HistoryNode> stack;
public:
    static int size();
    static bool empty();
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //SFML_TEST_HISTORY_H
