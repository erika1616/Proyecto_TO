#ifndef REY_H
#define REY_H
#include "piece.h"
#include "eje.h"
class rey: public Piece
{
public:
    rey(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // REY_H
