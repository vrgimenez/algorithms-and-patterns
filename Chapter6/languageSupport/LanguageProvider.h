#pragma once
#include <string>
#include <unordered_map>

class LanguageProvider {
public:
    virtual ~LanguageProvider() = default;

    // Get raw text by key: "ui.hello", "menu.exit"
    virtual std::string get(const std::string& key) const = 0;

    // Get text and substitute tags: {name}, {score}
    virtual std::string format(const std::string& key, const std::unordered_map<std::string, std::string>& args) const = 0;
};
