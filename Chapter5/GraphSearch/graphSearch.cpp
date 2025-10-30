#include "graphSearch.h"
#include <QThread>
#include <QApplication>

GraphSearch::GraphSearch(GraphicsConsole& gc) : gc(gc) {}

void GraphSearch::addNode(const std::string& label, int x, int y) {
    nodes.push_back({label, x, y});
}

void GraphSearch::addEdge(int from, int to, int weight) {
    edges.push_back({from, to, weight});
}

void GraphSearch::clear() {
    nodes.clear();
    edges.clear();
}

void GraphSearch::delay(int ms) {
    QThread::msleep(ms);
    gc.repaint();
}

void GraphSearch::draw() {
    gc.clear();

    // Draw edges
    gc.setColor(Qt::black);
    for (auto& e : edges)
        gc.drawLine(nodes[e.from].x, nodes[e.from].y, nodes[e.to].x, nodes[e.to].y);

    // Draw nodes
    for (auto& n : nodes) {
        gc.setColor(Qt::lightGray);
        gc.fillOval(n.x - 15, n.y - 15, 30, 30);
        gc.setColor(Qt::black);
        gc.drawText(n.x - 5, n.y + 5, QString::fromStdString(n.label));
    }
    gc.repaint();
}

void GraphSearch::highlightNode(int i, const QColor& color) {
    gc.setColor(color);
    gc.fillOval(nodes[i].x - 15, nodes[i].y - 15, 30, 30);
    gc.setColor(Qt::black);
    gc.drawText(nodes[i].x - 5, nodes[i].y + 5, QString::fromStdString(nodes[i].label));
    gc.repaint();
    QCoreApplication::processEvents();  
    QThread::msleep(250);
}

void GraphSearch::drawEdge(const Edge& e, const QColor& color) {
    gc.setColor(color);
    gc.drawLine(nodes[e.from].x, nodes[e.from].y, nodes[e.to].x, nodes[e.to].y);
    gc.repaint();
    QCoreApplication::processEvents();  
    QThread::msleep(250);
}

// ---------------- BFS ----------------
void GraphSearch::bfs(int start, int goal) {
    std::vector<bool> visited(nodes.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    draw();
    highlightNode(start, Qt::yellow);  // Discovered

    while (!q.empty()) {
        int v = q.front(); q.pop();

        // procesando nodo actual
        highlightNode(v, Qt::green);

        if (v == goal) {
            highlightNode(v, Qt::red);  // Destination found
            return;
        }

        for (auto& e : edges) {
            if (e.from == v && !visited[e.to]) {
                visited[e.to] = true;
                drawEdge(e, Qt::blue);  // Edge found
                highlightNode(e.to, Qt::yellow); // Discovered, pending to draw
                q.push(e.to);
            }
        }
    }
}

// ---------------- DFS ----------------
void GraphSearch::dfs(int start, int goal) {
    static std::vector<bool> visited(nodes.size(), false);

    visited[start] = true;
    highlightNode(start, Qt::green);
    QCoreApplication::processEvents();
    QThread::msleep(200);

    if (start == goal) {
        highlightNode(start, QColor(255, 0, 0)); // red — found
        QCoreApplication::processEvents();
        return;
    }

    for (auto& e : edges) {
        if (e.from == start && !visited[e.to]) {
            drawEdge(e, Qt::red);
            dfs(e.to, goal);
        }
    }
}