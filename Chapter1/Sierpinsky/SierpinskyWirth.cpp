#include <QApplication>
#include <QObject>
#include <iostream>
#include "graphicsConsole.h"

GraphicsConsole* pGc = nullptr;

int cx, cy, h;

void render();
void Sierpinsky(int r);
void A(int r);
void B(int r);
void C(int r);
void D(int r);
void lineTo(int newX, int newY);
void lineToT();
void lineToB();
void lineToR();
void lineToL();
void lineToTR();
void lineToTL();
void lineToBR();
void lineToBL();

void render()
{
    int maxx = pGc->getCanvas()->width();
    int maxy = pGc->getCanvas()->height();
    int menh = pGc->menuBar()->height();
    maxy+= menh;

    cx = maxx / 2;
    cy = maxy / 2;
    h = std::min(maxx,maxy) / 4;
    cy-= h;

    pGc->clear(Qt::black);
    pGc->setColor(Qt::red);

    for(char i = 0; i < 5; i++) {
        Sierpinsky(i);
        cx-= h;
        h /= 2;
        cy-= h;
    }
}

void Sierpinsky(int n)
{
    A(n);
    lineToBR();
    B(n);
    lineToBL();
    C(n);
    lineToTL();
    D(n);
    lineToTR();
}

void A(int n) {
    if(n > 0)
    {
        A(n-1);
        lineToBR();
        B(n-1);
        lineToR();
        lineToR();
        D(n-1);
        lineToTR();
        A(n-1);
    }
}

void B(int n) {
    if(n > 0)
    {
        B(n-1);
        lineToBL();
        C(n-1);
        lineToB();
        lineToB();
        A(n-1);
        lineToBR();
        B(n-1);
    }
}

void C(int n) {
    if(n > 0)
    {
        C(n-1);
        lineToTL();
        D(n-1);
        lineToL();
        lineToL();
        B(n-1);
        lineToBL();
        C(n-1);
    }
}

void D(int n) {
    if(n > 0)
    {
        D(n-1);
        lineToTR();
        A(n-1);
        lineToT();
        lineToT();
        C(n-1);
        lineToTL();
        D(n-1);
    }
}

void lineTo(int newX, int newY) {
   pGc->drawLine(cx, cy, newX, newY);
   cx = newX;
   cy = newY;
}

void lineToT() {
   lineTo(cx + 0, cy - h);
}
void lineToB() {
   lineTo(cx + 0, cy + h);
}
void lineToR() {
   lineTo(cx + h, cy + 0);
}
void lineToL() {
   lineTo(cx - h, cy + 0);
}
void lineToTR() {
   lineTo(cx + h, cy - h);
}
void lineToTL() {
   lineTo(cx - h, cy - h);
}
void lineToBR() {
   lineTo(cx + h, cy + h);
}
void lineToBL() {
   lineTo(cx - h, cy + h);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    pGc = &(GraphicsConsole::getInstance());
    QObject::connect(pGc, &GraphicsConsole::resized, []() { render(); });

    pGc->setWindowTitle("Sierpinsky");
    pGc->resize(1440, 900);
    pGc->show();

    render();

    return app.exec();
}