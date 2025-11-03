#include <QApplication>
#include "graphicsConsole.h"
#include "graphSearch.h"

GraphSearch* graph = nullptr;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GraphicsConsole& gc = GraphicsConsole::getInstance();
    gc.setWindowTitle("DFS / BFS Visualization");
    gc.resize(800, 600);
    gc.show();

    graph = new GraphSearch(gc);

    if (!graph->loadFromFile("graph.conf")) {
        qWarning("Could not load graph.conf");
        return -1;
    }

    graph->draw();

    // Run BFS first, then DFS (or comment one)
    //QTimer::singleShot(500, [](){ graph->bfs(0, 15); });  // Searches 0 to 4
    QTimer::singleShot(500, [](){ graph->dfs(0, 15); }); //Searches all paths

    return app.exec();
}