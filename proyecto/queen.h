#ifndef REINA_H
#define REINA_H
#include "piece.h"
#include "eje.h"
class reina: public Piece
{
public:
    reina(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // REINA_H
