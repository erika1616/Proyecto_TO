#ifndef TABLERO_H
#define TABLERO_H
#include <QGraphicsRectItem>
#include "piece.h"

class tablero
{
public:
    tablero();
    void dibujarBorde();
    void crearTablero(int x, int y);
    void dibujarCasillas(int x,int y);
    void addPieza();
    void setUpBlack();
    void setUpWhite();
    QList <Piece *> white;
    QList <Piece *> black;
    QList <Piece *> whiteD;
    QList <Piece *> blackD;
};

#endif // TABLERO_H
