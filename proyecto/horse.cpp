#include "horse.h"
#include "eje.h"
caballo::caballo(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setFigura();
}
void caballo::setFigura(){

    if(color == "WHITE"){
        this->setPixmap(QPixmap("://images/png_48/caballo1.png"));

    }else
        setPixmap(QPixmap("://images/png_48/caballo.png"));
}
QList<Coordenada> caballo::movimientos(){
     QList<Coordenada> opciones;

     if(getCuadrado()->fila+2 < 8 && getCuadrado()->columna+1 < 8 )
         opciones.append(Coordenada(this->getCuadrado()->columna+1,this->getCuadrado()->fila+2));
     if(getCuadrado()->fila+2 < 8 && getCuadrado()->columna-1 >= 0 )
         opciones.append(Coordenada(this->getCuadrado()->columna-1,this->getCuadrado()->fila+2));
     if(getCuadrado()->fila-2 >= 0 && getCuadrado()->columna+1 < 8 )
         opciones.append(Coordenada(this->getCuadrado()->columna+1,this->getCuadrado()->fila-2));
     if(getCuadrado()->fila-2 >= 0 && getCuadrado()->columna-1 >= 0)
         opciones.append(Coordenada(this->getCuadrado()->columna-1,this->getCuadrado()->fila-2));

     if(getCuadrado()->fila+1 < 8 && getCuadrado()->columna+2 < 8 )
         opciones.append(Coordenada(this->getCuadrado()->columna+2,this->getCuadrado()->fila+1));
     if(getCuadrado()->fila+1 < 8 && getCuadrado()->columna-2 >= 0 )
         opciones.append(Coordenada(this->getCuadrado()->columna-2,this->getCuadrado()->fila+1));
     if(getCuadrado()->fila-1 >= 0 && getCuadrado()->columna+2 < 8 )
         opciones.append(Coordenada(this->getCuadrado()->columna+2,this->getCuadrado()->fila-1));
     if(getCuadrado()->fila-1 >= 0 && getCuadrado()->columna-2 >= 0)
         opciones.append(Coordenada(this->getCuadrado()->columna-2,this->getCuadrado()->fila-1));
     return opciones;
}
