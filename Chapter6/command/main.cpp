#include <iostream>
#include "Editor.h"
#include "InsertTextCommand.h"
#include "DeleteTextCommand.h"
#include "CommandManager.h"

int main() {
    Editor editor;
    CommandManager mgr;

    mgr.execute(std::make_unique<InsertTextCommand>(editor, 0, "Hello "));
    mgr.execute(std::make_unique<InsertTextCommand>(editor, 6, "world!"));
    mgr.execute(std::make_unique<DeleteTextCommand>(editor, 5, 1)); // remove space

    std::cout << "Text: " << editor.getText() << "\n";

    mgr.undo();
    std::cout << "After undo: " << editor.getText() << "\n";

    mgr.undo();
    std::cout << "After second undo: " << editor.getText() << "\n";

    mgr.redo();
    std::cout << "After redo: " << editor.getText() << "\n";

    return 0;
}