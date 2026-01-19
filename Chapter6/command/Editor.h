#pragma once
#include <string>

class Editor {
    std::string text;

public:
    const std::string& getText() const { return text; }

    void insert(size_t pos, const std::string& value) {
        text.insert(pos, value);
    }

    std::string erase(size_t pos, size_t len) {
        std::string removed = text.substr(pos, len);
        text.erase(pos, len);
        return removed;
    }
};