#pragma once
#include <iostream>

class Logger {
public:
    void onButtonClicked() {
        std::cout << "[Logger] Button was clicked!\n";
    }
};
