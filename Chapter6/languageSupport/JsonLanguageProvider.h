#pragma once
#include "LanguageProvider.h"
#include <json.hpp>
#include <fstream>
#include <regex>
#include <sstream>

class JsonLanguageProvider : public LanguageProvider {
public:
    JsonLanguageProvider(const std::string& filename) {
        std::ifstream f(filename);
        if (!f.is_open())
            throw std::runtime_error("Could not open language file: " + filename);
        f >> data;
    }

    // Find a key like "hello" or "ui.hello"
    std::string get(const std::string& key) const override {
        const nlohmann::json* node = &data;
        std::stringstream ss(key);
        std::string seg;

        while (std::getline(ss, seg, '.')) {
            if (node->contains(seg))
                node = &(*node)[seg];
            else
                return "{" + key + "}"; // unknown tag → keep tag but show {}
        }

        if (node->is_string())
            return node->get<std::string>();
        return "{invalid:" + key + "}";
    }

    std::string format(
            const std::string& key,
            const std::unordered_map<std::string, std::string>& args) const override
    {
        std::string result = get(key);
        for (auto& [k, v] : args) {
            std::string token = "{" + k + "}";
            while (true) {
                size_t pos = result.find(token);
                if (pos == std::string::npos)
                    break;
                result.replace(pos, token.size(), v);
            }
        }
        return result;
    }

    std::string translateTags(const std::string& text) const {
        std::string out;
        out.reserve(text.size());

        std::regex r("\\{([a-zA-Z0-9._-]+)\\}");
        std::smatch m;

        std::string::const_iterator it = text.begin();
        std::string::const_iterator end = text.end();

        while (std::regex_search(it, end, m, r)) {
            // Append everything before the tag
            out.append(it, m.prefix().second);

            std::string key = m[1];
            out.append(get(key));  // Insert translation

            it = m.suffix().first; // Continue AFTER the match
        }

        // Append the rest of the string
        out.append(it, end);

        return out;
    }


private:
    nlohmann::json data;
};
