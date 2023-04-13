
#include "History.h"
#include <iostream>
std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    if (stack.size() > 1) stack.pop();

}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

bool History::empty() {
    return stack.empty();
}

int History::size() {
    return static_cast<int>(stack.size());
}
