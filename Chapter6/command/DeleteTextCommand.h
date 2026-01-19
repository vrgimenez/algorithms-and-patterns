#pragma once
#include "Command.h"
#include "Editor.h"
#include <string>

class DeleteTextCommand : public Command {
    Editor& editor;
    size_t pos;
    size_t len;

    // store deleted text for undo
    std::string removed;

public:
    DeleteTextCommand(Editor& ed, size_t p, size_t l)
        : editor(ed), pos(p), len(l) {}

    void execute() override {
        removed = editor.erase(pos, len);
    }

    void undo() override {
        editor.insert(pos, removed);
    }
};
