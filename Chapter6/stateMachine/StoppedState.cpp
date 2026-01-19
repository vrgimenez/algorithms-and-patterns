#include "StoppedState.h"
#include "PlayingState.h"
#include "Player.h"

void StoppedState::play(Player& player) {
    std::cout << "Starting playback...\n";
    player.setState(new PlayingState());
}
