#ifndef ALFIL_H
#define ALFIL_H
#include "piece.h"
#include "eje.h"
class alfil: public Piece
{
public:
    alfil(QString team,QGraphicsItem *parent = 0);
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // ALFIL_H
