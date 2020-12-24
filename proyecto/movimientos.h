#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "eje.h"
#include <QGraphicsPixmapItem>
class Movimientos:public QGraphicsPixmapItem
{
public:
    Movimientos(int b,QGraphicsItem *parent = 0);
    ~Movimientos();

    void setFigura();
    int a;

};

#endif // MOVIMIENTOS_H
