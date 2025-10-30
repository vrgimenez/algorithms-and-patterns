#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H

#include <QObject>
#include <vector>
#include <queue>
#include "graphicsConsole.h"

struct Edge {
    int from, to;
    int weight;
};

struct Node {
    std::string label;
    int x, y;
};

class GraphSearch : public QObject {
    Q_OBJECT

public:
    GraphSearch(GraphicsConsole& gc);
    void addNode(const std::string& label, int x, int y);
    void addEdge(int from, int to, int weight = 1);
    void clear();

    void draw();
    void bfs(int start, int goal);
    void dfs(int start, int goal);

private:
    GraphicsConsole& gc;
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    void highlightNode(int index, const QColor& color);
    void drawEdge(const Edge& e, const QColor& color);
    void delay(int ms);
};

#endif