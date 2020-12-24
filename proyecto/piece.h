#ifndef PIECE_H
#define PIECE_H
#include "eje.h"
#include <QGraphicsPixmapItem>
#include "square.h"
#include <QGraphicsSceneMouseEvent>
class cuadrado;
class Piece :public QGraphicsPixmapItem
{
public:
    Piece(QString team = "",QGraphicsItem *parent = 0);
    ~Piece();
    void setCuadrado(cuadrado *cuadrado);
    cuadrado *getCuadrado();
    virtual void setFigura()=0;
    virtual QList<Coordenada> movimientos()=0;
    QString getColor();
    void setColor( QString _color);
    void setPos2(qreal a , qreal b);
    QString ficha;
protected:
    QString color;
    cuadrado *miCuadrado;
};

#endif // PIECE_H
