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

    // Simple graph
    graph->addNode("0", 100, 300);
    graph->addNode("1", 300, 150);
    graph->addNode("2", 300, 450);
    graph->addNode("3", 500, 150);
    graph->addNode("4", 500, 450);

    graph->addEdge(0, 1);
    graph->addEdge(0, 2);
    graph->addEdge(1, 3);
    graph->addEdge(2, 4);
    graph->addEdge(3, 4);

    graph->draw();

    // Run BFS first, then DFS (or comment one)
    QTimer::singleShot(500, [](){ graph->bfs(0, 4); });  // Searches 0 to 4
    //QTimer::singleShot(500, [](){ graph->dfs(0, 4); }); //Searches all paths

    return app.exec();
}