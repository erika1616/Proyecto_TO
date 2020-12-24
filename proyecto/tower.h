#ifndef TORRE_H
#define TORRE_H
#include "piece.h"
#include "eje.h"
class torre: public Piece
{
public:
    torre(QString team,QGraphicsItem *parent = 0);
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // TORRE_H
