#pragma once
#include <iostream>

class Controller {
public:
    void onButtonClicked() {
        std::cout << "[Controller] Performing some action...\n";
    }
};
