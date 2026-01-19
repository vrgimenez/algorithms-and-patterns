#include "PausedState.h"
#include "PlayingState.h"
#include "StoppedState.h"
#include "Player.h"

void PausedState::play(Player& player) {
    std::cout << "Resuming...\n";
    player.setState(new PlayingState());
}

void PausedState::stop(Player& player) {
    std::cout << "Stopping...\n";
    player.setState(new StoppedState());
}
