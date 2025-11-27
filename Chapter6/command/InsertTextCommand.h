#pragma once
#include "Command.h"
#include "Editor.h"
#include <string>

class InsertTextCommand : public Command {
    Editor& editor;
    size_t pos;
    std::string text;

public:
    InsertTextCommand(Editor& ed, size_t p, std::string t)
        : editor(ed), pos(p), text(std::move(t)) {}

    void execute() override {
        editor.insert(pos, text);
    }

    void undo() override {
        editor.erase(pos, text.size());
    }
};