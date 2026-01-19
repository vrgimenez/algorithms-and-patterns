#pragma once
#include <string>
#include <iostream>

class Player;  // forward declaration

class State {
public:
    virtual ~State() = default;

    virtual void play(Player& player) = 0;
    virtual void pause(Player& player) = 0;
    virtual void stop(Player& player) = 0;

    virtual std::string name() const = 0;
};