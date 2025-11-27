#pragma once
#include <functional>
#include <vector>

template<typename... Args>
class Signal {
public:
    using Slot = std::function<void(Args...)>;

    void connect(const Slot& slot) {
        slots.push_back(slot);
    }

    void emit(Args... args) {
        for (auto& s : slots) {
            s(args...);
        }
    }

private:
    std::vector<Slot> slots;
};
