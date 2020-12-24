#include "king.h"
#include "eje.h"
rey::rey(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setFigura();
}
void rey::setFigura(){

    if(color == "WHITE"){
        this->setPixmap(QPixmap("://images/png_48/rey1.png"));

    }else
        setPixmap(QPixmap("://images/png_48/rey.png"));
}
QList<Coordenada> rey::movimientos(){
    QList<Coordenada>opciones;

    if(this->getCuadrado()->columna-1>=0 && this->getCuadrado()->fila-1>=0)
        opciones.append(Coordenada(this->getCuadrado()->columna-1, this->getCuadrado()->fila-1));
    if(this->getCuadrado()->columna+1<8 && this->getCuadrado()->fila+1<8)
        opciones.append(Coordenada( this->getCuadrado()->columna+1, this->getCuadrado()->fila+1));
    if(this->getCuadrado()->columna+1>=0 && this->getCuadrado()->fila-1>=0)
        opciones.append(Coordenada(this->getCuadrado()->columna+1,this->getCuadrado()->fila-1));
    if(this->getCuadrado()->columna-1>=0 && this->getCuadrado()->fila+1>=0)
        opciones.append(Coordenada(this->getCuadrado()->columna-1, this->getCuadrado()->fila+1));


    if(this->getCuadrado()->fila-1>=0)
        opciones.append(Coordenada(this->getCuadrado()->columna, this->getCuadrado()->fila-1));
    if(this->getCuadrado()->fila+1<8)
        opciones.append(Coordenada(this->getCuadrado()->columna, this->getCuadrado()->fila+1));
    if(this->getCuadrado()->columna+1<8)
        opciones.append(Coordenada(this->getCuadrado()->columna+1, this->getCuadrado()->fila));
    if(this->getCuadrado()->columna-1>=0)
        opciones.append(Coordenada( this->getCuadrado()->columna-1,this->getCuadrado()->fila));
    return opciones;



}
