//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_STATES_H
#define SFML_TEST_STATES_H
#include "StateEnum.h"
#include <map>
class States {
private:
    std::map<StateEnum, bool> states;
public:
    States();
    bool isEnabled(StateEnum state) const;
    void enableState(StateEnum state);
    void disableState(StateEnum state);
    void toggleState(StateEnum state);
};
#endif //SFML_TEST_STATES_H
