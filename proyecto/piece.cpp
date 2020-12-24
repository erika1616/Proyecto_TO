#include "piece.h"
#include "square.h"


Piece::Piece(QString team,QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    color = team;
}
Piece::~Piece(){

}

QString Piece::getColor()
{
    return color;
}

void Piece::setColor( QString _color)
{
    color = _color;
}
void Piece::setCuadrado(cuadrado *cuadrado)
{

    miCuadrado = cuadrado;
}

void Piece::setPos2(qreal a , qreal b){
    setPos(a,b);
}
cuadrado *Piece::getCuadrado(){
    return miCuadrado;
}
