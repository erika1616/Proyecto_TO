#include "movimientos.h"

Movimientos::Movimientos(int b,QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    a=b;
    setFigura();
}
void Movimientos::setFigura(){
     this->setPixmap(QPixmap("://images/png_48/opciones2.png"));
}

Movimientos::~Movimientos(){
}
