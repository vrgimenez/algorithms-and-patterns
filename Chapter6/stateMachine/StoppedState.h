#pragma once
#include "State.h"

class StoppedState : public State {
public:
    void play(Player& player) override;
    void pause(Player&) override {
        std::cout << "Pause ignored — player is stopped.\n";
    }
    void stop(Player&) override {
        std::cout << "Already stopped.\n";
    }
    std::string name() const override { return "Stopped"; }
};