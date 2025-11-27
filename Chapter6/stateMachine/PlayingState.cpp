#include "PlayingState.h"
#include "PausedState.h"
#include "StoppedState.h"
#include "Player.h"

void PlayingState::pause(Player& player) {
    std::cout << "Pausing...\n";
    player.setState(new PausedState());
}

void PlayingState::stop(Player& player) {
    std::cout << "Stopping playback...\n";
    player.setState(new StoppedState());
}
