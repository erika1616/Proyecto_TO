#ifndef CABALLO_H
#define CABALLO_H
#include "piece.h"
#include "eje.h"

class caballo: public Piece
{
public:
    caballo(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};
#endif // CABALLO_H
