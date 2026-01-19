#include <iostream>
#include "Player.h"
#include "StoppedState.h"

int main() {
    Player player(new StoppedState());

    std::cout << "Initial state: Stopped\n\n";

    player.play();   // Stopped → Playing
    //player.play();   // Playing -> does nothing
    player.pause();  // Playing → Paused
    player.play();   // Paused → Playing
    player.stop();   // Playing → Stopped

    return 0;
}