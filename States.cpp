//
// Created by Allen Lam on 3/23/22.
//

#include "States.h"

bool States::isEnabled(StateEnum state) const {
    return states.at(state);
}

void States::enableState(StateEnum state) {
    states[state] = true;
}

void States::disableState(StateEnum state) {
    states[state] = false;
}

States::States() {
    for (int i = 0; i < LASTSTATE; ++i) {
        states[static_cast<StateEnum>(i)] = false;
    }
}

void States::toggleState(StateEnum state) {
    states[state] = !states[state];

}
