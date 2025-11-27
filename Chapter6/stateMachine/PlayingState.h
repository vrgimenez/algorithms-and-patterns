#pragma once
#include "State.h"

class PlayingState : public State {
public:
    virtual ~PlayingState()  { std::cout << "Destroying state " << this->name() << std::endl; }
    void play(Player&) override {
        std::cout << "Already playing.\n";
    }
    void pause(Player& player) override;
    void stop(Player& player) override;
    std::string name() const override { return "Playing"; }
};