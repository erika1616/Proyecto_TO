#ifndef PEON_H
#define PEON_H
#include "piece.h"
#include "eje.h"
class Peon: public Piece
{
public:
    Peon(QString team,QGraphicsItem *parent = 0);
    bool primerMov = true;
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // PEON_H
