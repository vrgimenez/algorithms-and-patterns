#pragma once
#include "Command.h"
#include <stack>
#include <memory>

class CommandManager {
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;

public:
    void execute(std::unique_ptr<Command> cmd) {
        cmd->execute();
        undoStack.push(std::move(cmd));

        // any new command clears redo history
        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() {
        if (undoStack.empty()) return;

        auto cmd = std::move(undoStack.top());
        undoStack.pop();

        cmd->undo();
        redoStack.push(std::move(cmd));
    }

    void redo() {
        if (redoStack.empty()) return;

        auto cmd = std::move(redoStack.top());
        redoStack.pop();

        cmd->execute();
        undoStack.push(std::move(cmd));
    }
};