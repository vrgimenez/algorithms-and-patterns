#include <iostream>
#include "button.h"
#include "logger.h"
#include "controller.h"

int main() {
    Button btn;
    Logger logger;
    Controller controller;

    // Connect signals to slots
    btn.clicked.connect([&]() { logger.onButtonClicked(); });
    btn.clicked.connect([&]() { controller.onButtonClicked(); });

    std::cout << "Pressing button...\n";
    btn.press();

    return 0;
}
