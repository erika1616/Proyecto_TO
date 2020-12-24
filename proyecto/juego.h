#ifndef JUEGO_H
#define JUEGO_H
#include "cuadrado.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class Juego:public QGraphicsView
{
public:
    Juego(QWidget *parent = 0);
    cuadrado *collection[8][8];

private:
    QGraphicsScene *gameScene;
};

#endif // JUEGO_H
