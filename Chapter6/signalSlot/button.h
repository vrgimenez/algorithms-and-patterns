#pragma once
#include <string>
#include "signal.h"

class Button {
public:
    Signal<> clicked;  // signal with no parameters

    void press() {
        // simulate a button being pressed
        clicked.emit();
    }
};
