#pragma once
#include "State.h"

class Player {
    State* state;   // current state
public:
    Player(State* initialState) : state(initialState) {}

    void setState(State* newState) {
        std::cout << "State → " << newState->name() << "\n";
        if (state != nullptr) {
            delete state;
        }
        state = newState;
    }

    void play()  { state->play(*this); }
    void pause() { state->pause(*this); }
    void stop()  { state->stop(*this); }
};