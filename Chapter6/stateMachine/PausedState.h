#pragma once
#include "State.h"

class PausedState : public State {
public:
    virtual ~PausedState()  { std::cout << "Destroying state " << this->name() << std::endl; }
    void play(Player& player) override;
    void pause(Player&) override {
        std::cout << "Already paused.\n";
    }
    void stop(Player& player) override;
    std::string name() const override { return "Paused"; }
};
