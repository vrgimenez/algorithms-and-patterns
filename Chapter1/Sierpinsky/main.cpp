#include <QApplication>
#include "graphicsConsole.h"
#include <cmath>
// #include <iostream>

const double DEG2RAD = M_PI / 180.0;

GraphicsConsole *pGc = nullptr;

void sierpinski(GraphicsConsole& gc,
                double x, double y,
                double len,
                double angle,
                int level,
                int dir) // +1 or -1 (sentido de rotación)
{
    //std::cout << "sierpinski x1=" << x << ", y1= " << y << ", len=" << len << ", angle= " << angle << ", level=" << level << ", dir=" << dir << std::endl;
    if (level == 0) {
        double nx = x + len * cos(angle * DEG2RAD);
        double ny = y - len * sin(angle * DEG2RAD);
        gc.drawLine(x, y, nx, ny);
        return;
    }

    len /= 2.0;

    // Regla recursiva:
    // A → B−A−B
    // B → A+B+A
    sierpinski(gc, x, y, len, angle + dir * 60, level - 1, -dir);

    double x1 = x + len * cos((angle + dir * 60) * DEG2RAD);
    double y1 = y - len * sin((angle + dir * 60) * DEG2RAD);
    sierpinski(gc, x1, y1, len, angle, level - 1, dir);

    double x2 = x1 + len * cos(angle * DEG2RAD);
    double y2 = y1 - len * sin(angle * DEG2RAD);
    sierpinski(gc, x2, y2, len, angle - dir * 60, level - 1, -dir);
}

void render() {
    // Calculate depending on screen size
    double canvasW = pGc->getCanvas()->width();
    double canvasH = pGc->getCanvas()->height();
    double length = std::min(canvasW * 0.8, (canvasH * 2.0 / std::sqrt(3)) * 0.9);
    double triHeight = (std::sqrt(3) / 2.0) * length;
    double x = (canvasW - length) / 2.0;
    double y = canvasH - triHeight * .18;
    int depth = std::max(1, static_cast<int>(std::log2(length / 10.0)));

    pGc->setColor(Qt::black);
    sierpinski(*pGc, x, y, length, 0, depth, 1);
    pGc->show();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    pGc = &(GraphicsConsole::getInstance());
    QObject::connect(
        pGc, &GraphicsConsole::resized, 
        []() { render(); }    // call your C-style function
    );

    pGc->setWindowTitle("Sierpinsky...");
    pGc->resize(1000, 900);
    pGc->show();

    render();
    
    return app.exec();
}